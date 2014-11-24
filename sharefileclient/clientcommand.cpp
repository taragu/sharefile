#include "clientcommand.h"
#include <iostream>
#include <string>
#include <set>
#include <QDebug>
#define COMMAND_BUF_SIZE  256
#define END 1234

ClientCommand::ClientCommand( const char *ip, int port )
{
    struct sockaddr_in addr ;
    bzero( &addr, sizeof(addr) ) ;
    m_sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ;
    if ( -1 == m_sockfd )
    {
        perror( "socket" ) ;
        return ;
    }
    addr.sin_family = AF_INET ;
    addr.sin_port = htons( port ) ;
    addr.sin_addr.s_addr = inet_addr( ip ) ;
    if ( -1 == connect( m_sockfd, (SA*)&addr, sizeof(addr) ) )
    {
        perror( "connect" ) ;
        return ;
    }
    m_bstart = true ;
}

ClientCommand::~ClientCommand( void )
{
    if ( m_bstart )
    {
        close( m_sockfd ) ;
    }
}


int ClientCommand::QuitCommand( void )
{
    int retval = 0 ;
    // send command
    if ( write( m_sockfd, COMMAND_QUIT, strlen(COMMAND_QUIT) ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
    if ( m_bstart )
    {
        close( m_sockfd ) ;
        m_bstart = false ;
    }
done:
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// get file
int ClientCommand::GetCommand( const char *fileName ) const
{

    int retval = 0 ;
    char command[COMMAND_BUF_SIZE] ;
    bzero( command, sizeof(command) ) ;
    char buffer[RECV_BUF_SIZE] ;
    bzero( buffer, sizeof(buffer) ) ;
    strcpy( command, COMMAND_GET ) ;
    strcat( command, fileName ) ;
    ssize_t rbyte = 0 ;
    // int i = 1 ;
    int fd = open( fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644 ) ;
    if ( write( m_sockfd, command, strlen( command ) ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
    if ( -1 == fd )
    {
        perror( "open" ) ;
        goto error ;
    }
    while ( (rbyte = read( m_sockfd, buffer, sizeof(buffer) ) ) > 0 )
    {
        if ( write( fd, buffer, rbyte ) < 0 )
        {
            perror( "write" ) ;
            goto error ;
        }
        if ( (rbyte < RECV_BUF_SIZE) )
        {
            goto done ;
        }

    }
done:
    close( fd ) ;
    return retval ;
error:
    retval = - 1 ;
    goto done ;
}

// upload
int ClientCommand::PutCommand( const char *fileName ) const
{
    int retval = 0 ;
    char command[COMMAND_BUF_SIZE] ;
    bzero( command, sizeof(command) ) ;
    char sendbuf[SEND_BUF_SIZE] ;
    bzero( sendbuf, sizeof(sendbuf) ) ;
    // send command
    strcpy( command, COMMAND_PUT ) ;
    strcat( command, fileName ) ;
    int fd = open( fileName, O_RDONLY ) ;
    ssize_t rbyte = 0 ;
    if ( write( m_sockfd, command, strlen(command) ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
    if ( -1 == fd )
    {
        perror( "open" ) ;
        goto error ;
    }
    while ( (rbyte = read( fd, sendbuf, sizeof(sendbuf) )) >= 0 )
    {
        if ( write( m_sockfd, sendbuf, rbyte ) < 0 )
        {
            perror( "write" ) ;
            goto error ;
        }
        if ( (rbyte < SEND_BUF_SIZE) )
        {
            goto done ;
        }
    }
done:
    close( fd ) ;
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// help
int ClientCommand::HelpCommand( void ) const
{
    std::cout << "help               show help" << std::endl ;
    std::cout << "ls                 show contents under current directory" << std::endl ;
    std::cout << "get <filename>     download file from server" << std::endl ;
    std::cout << "put <filename>     upload file to server" << std::endl ;
    std::cout << "cd  <filename>     enter a directory" << std::endl ;
    std::cout << "by                 quit" << std::endl;
    return 0 ;
}


std::set<std::string> ClientCommand::LsCommand( void ) const
{
    std::set<std::string> returnSet;
    int retval = 0 ;
    char filename[RECV_BUF_SIZE] ;
    bzero( filename, sizeof(filename) ) ;
    // send command
    if ( write( m_sockfd, COMMAND_LS, strlen(COMMAND_LS) ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
    while( read( m_sockfd, filename, sizeof(filename) ) > 0  )
    {
        if ( END == *(int*)filename )
        {
            //printf( "\n" ) ;
            goto done ;
        }
        else if ( DT_DIR == *(int*)filename )
        {
            //printf( "\033[0;34m%s\033[0m \t", filename+sizeof(int) ) ;
        }
        else
        {
            //printf( "%s \t", filename+sizeof(int) ) ;
            returnSet.insert(std::string(filename));
        }
        fflush( stdout ) ;
        bzero( filename, sizeof(filename) ) ;
    }
done:
    return returnSet;
error:
    retval = - 1;
    goto done ;
}


int ClientCommand::CdCommand( const char *path )
{
    int retval = 0 ;
    char command[COMMAND_BUF_SIZE] ;
    bzero( command, sizeof(command) ) ;
    strcpy( command, COMMAND_CD ) ;
    strcat( command, path ) ;
    if ( write( m_sockfd, command, strlen(command) ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
done:
    return retval ;
error:
    goto done ;
}

int ClientCommand::manager( void )
{
    char command[COMMAND_BUF_SIZE] ;
    for ( ; m_bstart; )
    {
        bzero( command, sizeof(command) ) ;
        std::cout << "shareFile>" ;
        fgets( command, sizeof(command), stdin ) ;
        std::string str = command ;

        std::string cmd ;
        std::string file ;
        std::string::size_type start = str.find_first_not_of( ' ', 0 ) ;
        std::string::size_type end = str.find_first_of( ' ', start ) ;
        // printf( "%lu:%lu\n", start, end ) ;
        if ( std::string::npos != end )
        {
            cmd = str.substr( start, end - start ) ;
            start = str.find_first_not_of( ' ', end ) ;
            end = str.find_first_of( '\n', start ) ;
            file = str.substr( start, str.length()-start-1 ) ;
        }
        else
        {
            cmd = str.substr( start, str.length()-1 ) ;
        }

        if ( COMMAND_LS == cmd )
        {
            LsCommand() ;
        }
        else if ( COMMAND_PUT == cmd )
        {
            PutCommand( file.c_str() ) ;
        }
        else if ( COMMAND_GET == cmd )
        {
            GetCommand( file.c_str() ) ;
        }
        else if ( COMMAND_QUIT == cmd )
        {
            QuitCommand( ) ;
        }
        else if ( COMMAND_CD == cmd )
        {
            CdCommand( file.c_str() ) ;
        }
        else if (COMMAND_HELP == cmd )
        {
            HelpCommand( ) ;
        }
    }
    return 0 ;
}

