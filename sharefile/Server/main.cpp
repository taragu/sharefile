#include "servercommand.h"
#include <stdio.h>
#include <pthread.h>

#include "user_db_editor.h"
#include <sqlite3.h>

#define COMMAND_BUF      256

typedef struct sockaddr SA ;

// Client thread
void *clientthread( void *arg )
{
	long int retval = 0 ;
	int clientfd = *(int*)arg ;
	ServerCommand command( clientfd ) ;
	char commandbuf[COMMAND_BUF] ;
	while ( 1)
	{
		bzero( commandbuf, COMMAND_BUF ) ;
		// receive command
		if ( read( clientfd, commandbuf, COMMAND_BUF) <= 0 )
		{
			goto error ;
		}
		std::cout << "command:" << commandbuf << std::endl ;
        // do command
		if ( !strncmp( COMMAND_LS, commandbuf, strlen(COMMAND_LS) ) )
		{
		  cout<< "ls works" << endl;
			if ( -1 == command.LsCommand( ) )
			{
				goto error ;
			}
		}
		else if ( !strncmp( COMMAND_LSF, commandbuf, strlen(COMMAND_LSF) ) )
		{
		  cout<< "lsf works " << endl;
			if ( -1 == command.LsfCommand( ) )
			{
				goto error ;
			}
		}
		else if ( !strncmp( COMMAND_LSM, commandbuf, strlen(COMMAND_LSM) ) )
		{
		  cout<< " it is the command " << endl;
			if ( -1 == command.LsmCommand( ) )
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
		else if ( !strncmp( COMMAND_SEND, commandbuf, strlen(COMMAND_SEND) ) )
		{
			if ( -1 == command.SendCommand( ) )
			{
				goto error ;
			}
		}
		else if ( !strncmp( COMMAND_AP, commandbuf, strlen(COMMAND_SEND) ) )
		{
			if ( -1 == command.ApCommand( ) )
			{
				goto error ;
			}
		}
		else if ( !strncmp( COMMAND_UN, commandbuf, strlen(COMMAND_SEND) ) )
		{
			if ( -1 == command.UnCommand( ) )
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
	//	cout << "wrong command" << endl;
	goto done ;
}

int main( int argc, char **argv )
{
	if ( argc < 2 )
	{
		std::cerr << "Enter:" << argv[0] << "<Port>" << std::endl ;
		return - 1;
	}
	user_db_editor ude;
	ude.user_db_editor::DbInitialize();
	// prepare to listen
	int listenfd = socket( AF_INET, SOCK_STREAM, 0 ) ;
	if ( - 1 == listenfd )
	{
		perror( "listen" ) ;
		return -1 ;
	}
	// prepare to bind
	struct sockaddr_in addrserver ;
	bzero( &addrserver, sizeof(addrserver) ) ;
	addrserver.sin_family = AF_INET ;
	addrserver.sin_port = htons( atoi( argv[1] ) );
	socklen_t len = sizeof(addrserver) ;
	// start binding
	if ( -1 == bind( listenfd, (SA*)&addrserver, len ) )
	{
		perror( "bind" ) ;
		return -1 ;
	}
	// listen
	if ( -1 == listen( listenfd, 32 ) )
	{
		perror( "listen" ) ;
		return -1 ;
	}

	for( ; ; )
	{
		struct sockaddr_in addrcli ;
		socklen_t len = sizeof(addrcli) ;
		bzero( &addrcli, len ) ;
		// wait for client
		int clientfd = accept( listenfd, (SA*)&addrcli, &len ) ;
		if ( -1 == clientfd )
		{
			perror( "accept" ) ;
			return -1 ;
		}
		pthread_t tid ;
		pthread_attr_t attr ;
		pthread_attr_init( &attr ) ;
		if ( pthread_attr_setstacksize( &attr, 4096 * 10 ) )
		{
			perror( "phread_attr_setstacksize" ) ;
			return -1 ;
		}
		if ( pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_DETACHED ) )
		{
			perror( "pthread_attr_setdetached" ) ;
			return -1 ;
		}
		if ( pthread_create( &tid, &attr, clientthread, new int( clientfd ) ) )
		{
			perror( "pthread_create" ) ;
			return - 1;
		}
	}
}
