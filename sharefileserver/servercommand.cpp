#include "servercommand.h"

#define END 1234
using namespace std ;


ServerCommand::ServerCommand( int sockfd ) :
    m_sockfd( sockfd )
{
    m_serverpath = "." ;
    m_fd = open( "userdata.dat", O_CREAT | O_RDWR, 0644 ) ;
    if ( -1 == m_fd )
    {
        perror( "open" ) ;
    }
    UserData data ;
    memset( &data, 0, sizeof(data) ) ;
    while ( read( m_fd, &data, sizeof(data) ) > 0 )
    {
        m_Datas.insert( data ) ;
    }
}

ServerCommand::~ServerCommand( void )
{
    if ( !m_bstart )
    {
        return ;
    }
    close( m_fd ) ;
    close( m_sockfd ) ;
}

// content of client directory
int ServerCommand::LsCommand( void ) const
{
    DIR *mydir = NULL ;
    int retval = 0 ;
    char fileName[SEND_BUF_SIZE] ;
    bzero( fileName, sizeof(fileName) ) ;
    struct dirent *pdir = NULL ;
    if ( !(mydir = opendir( m_userpath.c_str() )) )
    {
        perror( "opendir" ) ;
        goto error ;
    }
    while ( (pdir = readdir(mydir)) )
    {
        bzero( fileName, sizeof(fileName) ) ;
        // cout << pdir << endl ;
        *(int*)fileName = pdir->d_type ;
        if ( !memcpy( fileName+sizeof(int), pdir->d_name, strlen(pdir->d_name) ) )
        {
            perror( "memcpy" ) ;
            goto error ;
        }
        if ( write( m_sockfd, fileName, SEND_BUF_SIZE ) < 0 )
        {
            perror( "write" ) ;
            goto error ;
        }
        // printf( "while\n" ) ;
    }
    *(int*)fileName = END ;
    if ( write( m_sockfd, fileName, SEND_BUF_SIZE ) < 0 )
    {
        perror( "write" ) ;
        goto error ;
    }
done:
    closedir( mydir ) ;
    // cout << "LsCommand:End" << endl ;
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// client out
int ServerCommand::QuitCommand( ) const
{
    cout << "One client disconnects" << endl;
    return close( m_sockfd ) ;
}

// Download file
int ServerCommand::GetCommand( const char *fileName ) const
{
    cout << "GetCommand" << endl ;
    string file = m_userpath + "/" + fileName ;
    char buffer[SEND_BUF_SIZE] ;
    bzero( buffer, sizeof(buffer) ) ;
    cout << "[get]" << file << endl ;
    int fd = open( file.c_str(), O_RDONLY ) ;
    if ( -1 == fd )
    {
        cerr << "openfile:" << file << endl ;
        return -1 ;
    }
    ssize_t rbyte = 0 ;
    while ( (rbyte = read( fd, buffer, sizeof(buffer)) ) >= 0 )
    {
        if ( (write( m_sockfd, buffer, rbyte) ) < 0 )
        {
            perror( "write" ) ;
            close( fd ) ;
            close( m_sockfd ) ;
            return -1 ;
        }
        if ( (rbyte < SEND_BUF_SIZE) )
        {
            goto done ;
        }

    }
done:
    close( fd ) ;
    cout << "GetCommand:End" << endl ;
    return 0 ;
}

// upload file
int ServerCommand::PutCommand( const char *fileName ) const
{
    char buffer[RECV_BUF_SIZE] ;
    bzero( buffer, sizeof(buffer) ) ;
    string file = m_userpath + "/" + fileName ;
    cout << "[put]" << file << endl ;
    int fd = open( file.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644 ) ;
    if ( -1 == fd )
    {
        cerr << "openfile:" << file << endl ;
        return -1 ;
    }
    ssize_t rbyte = 0 ;
    while ( (rbyte = read( m_sockfd, buffer, RECV_BUF_SIZE )) > 0 )
    {
        if ( write( fd, buffer, rbyte ) < 0 )
        {
            perror( "writefile" ) ;
            close( fd ) ;
            return -1 ;
        }
        cout << "rbyte:" << rbyte << endl ;
        if ( (rbyte < RECV_BUF_SIZE) )
        {
            goto done ;
        }
    }
done:
    cout << "Done receiving" << endl ;
    return close( fd ) ;
}

int ServerCommand::HelpCommand( void ) const
{
    cout << "help" << endl ;
    return 0 ;
}

// change directories
int ServerCommand::CdCommand( const char *dir )
{
    if ( ('/' == dir[0]) )
    {
        m_userpath = dir ;
    }
    else
    {
        m_userpath = m_userpath + "/" + dir ;
    }
    return 0 ;
}

// login on
int ServerCommand::LoginCommand( void )
{
    int retval = 0 ;
    UserData user ;
    int replay = 0 ;
    int trycount = 3 ;
retry:
    set<UserData>::iterator it ;
    if ( read( m_sockfd, &user, sizeof(user) ) < 0 )
    {
        perror( "read" ) ;
        goto error ;
    }
    cout << user.username << endl ;
    cout << user.password << endl ;
    it = m_Datas.find( user ) ;
    if ( m_Datas.end() != it )
    {
        cout << it->username << endl ;
        cout << it->password << endl ;
        if ( !strcmp( it->password, user.password ) )
        {
            replay = 0 ;
        }
        else
        {
            replay = -1 ;
        }
    }
    else
    {
        replay = -1 ;
    }
    // result of verification
    cout << "replay:" << replay << endl ;
    write( m_sockfd, &replay, sizeof(replay) ) ;
    if ( -1 == replay && trycount )
    {
        --trycount ;
        goto retry ;
    }
    else if ( -1 == replay )
    {
        goto error ;
    }
    m_username = it->username ;
    m_password = it->password ;
    m_userpath = m_serverpath + "/" + it->username ;
done:
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// register
int ServerCommand::RegisterCommand( void )
{
    int retval = 0 ;
    UserData user ;
    int replay = 0 ;
    int trycount = 3 ;
    set<UserData>::iterator it ;
retry:
    if ( read( m_sockfd, &user, sizeof(user) ) < 0 )
    {
        perror( "read" ) ;
        goto error ;
    }
    cout << user.username << endl ;
    cout << user.password << endl ;
    it = m_Datas.find( user ) ;
    if ( m_Datas.end() == it )
    {
        m_Datas.insert( user ) ;
        replay = 0 ;
    }
    else
    {
        replay = -1 ;
    }
    // sending result
    cout << "replay:" << replay << endl ;
    write( m_sockfd, &replay, sizeof(replay) ) ;
    if ( -1 == replay && trycount )
    {
        --trycount ;
        goto retry ;
    }
    else if ( -1 == replay )
    {
        goto error ;
    }
    m_username = it->username ;
    m_password = it->password ;
    m_userpath = m_serverpath + "/" + user.username ;
    cout << "m_userpath" << m_userpath << endl;
    if ( -1 == mkdir( m_userpath.c_str(), 0775 ) )
    {
        perror( "mkdir" ) ;
        goto error ;
    }
    m_Datas.insert( user ) ;
    if ( write( m_fd, &user, sizeof(user) ) < 0 )
    {
        perror( "m_userfile.write" ) ;
        goto error ;
    }
done:
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// share
int ServerCommand::ShareCommand( void )
{
    cout << "COMMAND_SHARE" << endl;
    int retval = 0 ;
    char file[256] ;
    char user[256] ;
    bzero( file, sizeof(file) ) ;
    bzero( user, sizeof(user) ) ;
    string _newfile ;
    string oldfile ;
    // obatain file name and username
    if ( read( m_sockfd, file, sizeof(file) ) < 0 )
    {
        perror( "read filename" ) ;
        goto error ;
    }
    if ( read( m_sockfd, user, sizeof(user) ) < 0 )
    {
        perror( "read username" ) ;
        goto error ;
    }
    cout << file << ":" << user << endl ;
    _newfile = m_serverpath + "/" + user + "/" + file ;
    oldfile = m_userpath + "/" + file ;
    cout << _newfile << endl ;
    if ( -1 == link( oldfile.c_str(), _newfile.c_str() ) )
    {
        perror( "link" ) ;
        goto error ;
    }
done:
    cout << "COMMAND_SHARE END" << endl ;
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

int ServerCommand::RmCommand( string filename )
{
    string file = m_userpath + "/" + filename ;
    cout << "file:" << file << endl ;
    return unlink( file.c_str() ) ;
}

bool ServerCommand::FindUser( const string &username ) const
{
    UserData user( username ) ;
    return m_Datas.end() != m_Datas.find( user ) ;
}
