#include "task.h"

typedef struct sockaddr SA;

Task::Task( int port)
{
    m_listenfd = socket( AF_INET, SOCK_STREAM, 0 ) ;
    if ( - 1 == m_listenfd )
    {
        perror( "listen" ) ;
        return;
    }
    // prepare to bind
    struct sockaddr_in addrserver ;
    bzero( &addrserver, sizeof(addrserver) ) ;
    addrserver.sin_family = AF_INET ;
    addrserver.sin_port = htons(port);
    socklen_t len = sizeof(addrserver) ;
    // start binding
    if ( -1 == bind( m_listenfd, (SA*)&addrserver, len ) )
    {
        perror( "bind" ) ;
        return;
    }
    // listen
    if ( -1 == listen( m_listenfd, 32 ) )
    {
        perror( "listen" ) ;
        return;
    }
}

Task::~Task(void)
{
    close(m_listenfd);
}

void *Task::clientthread (void * arg)
{
    long int retval = 0 ;
    int m_clientfd = *(int*)arg ;
    ServerCommand command( m_clientfd ) ;
    char commandbuf[COMMAND_BUF] ;
    while ( 1)
    {
        bzero( commandbuf, COMMAND_BUF ) ;
        // receive command
        if ( read( m_clientfd, commandbuf, COMMAND_BUF) <= 0 )
        {
            goto error ;
        }
        std::cout << "command:" << commandbuf << std::endl ;
        // do command
        if ( !strncmp( COMMAND_LS, commandbuf, strlen(COMMAND_LS) ) )
        {
            if ( -1 == command.LsCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_GET, commandbuf, strlen(COMMAND_GET) ) )
        {
            if ( -1 == command.GetCommand( commandbuf+strlen(COMMAND_GET) ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_PUT, commandbuf, strlen(COMMAND_PUT) ) )
        {
            if ( -1 == command.PutCommand( commandbuf+strlen(COMMAND_PUT) ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_HELP, commandbuf, strlen(COMMAND_HELP) ) )
        {
            if ( -1 == command.HelpCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_QUIT, commandbuf, strlen(COMMAND_QUIT) ) )
        {
            if ( -1 == command.QuitCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_CD, commandbuf, strlen(COMMAND_CD) ) )
        {
            if ( -1 == command.CdCommand( commandbuf+strlen(COMMAND_CD) ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_LOGIN, commandbuf, strlen(COMMAND_LOGIN) ) )
        {
            if ( -1 == command.LoginCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_LOGON, commandbuf, strlen(COMMAND_LOGON) ) )
        {
            if ( -1 == command.LogonCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_SHARE, commandbuf, strlen(COMMAND_SHARE) ) )
        {
            if ( -1 == command.ShareCommand( ) )
            {
                goto error ;
            }
        }
        else if ( !strncmp( COMMAND_RM, commandbuf, strlen(COMMAND_RM) ) )
        {
            if ( -1 == command.RmCommand( commandbuf+strlen(COMMAND_RM) ) )
            {
                goto error ;
            }
        }
    }
done:
    delete (int*)arg ;
    return (void*)retval ;
error:
    retval = -1 ;
    goto done ;
}



void Task::start()
{
    for( ; ; )
    {
        struct sockaddr_in addrcli ;
        socklen_t len = sizeof(addrcli) ;
        bzero( &addrcli, len ) ;
        // wait for client
        int m_clientfd = accept( m_listenfd, (SA*)&addrcli, &len ) ;
        if ( -1 == m_clientfd )
        {
            perror( "accept" ) ;
            return ;
        }
        pthread_t tid ;
        pthread_attr_t attr ;
        pthread_attr_init( &attr ) ;
        if ( pthread_attr_setstacksize( &attr, 4096 * 10 ) )
        {
            perror( "phread_attr_setstacksize" ) ;
            return ;
        }
        if ( pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_DETACHED ) )
        {
            perror( "pthread_attr_setdetached" ) ;
            return ;
        }
        if ( pthread_create( &tid, &attr, Task::clientthread, new int( m_clientfd ) ) )
        {
            perror( "pthread_create" ) ;
            return ;
        }
    }
}















