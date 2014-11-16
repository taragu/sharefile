#ifndef _COMMAND_H
#define _COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <fcntl.h>
#include <strings.h>
#include <errno.h>

#include <iostream>
#include <vector>
#include <string>

#define COMMAND_QUIT      "by"
#define COMMAND_GET       "get"
#define COMMAND_HELP      "help"
#define COMMAND_PUT       "put"
#define COMMAND_LS        "ls"
#define COMMAND_CD        "cd"

#define RECV_BUF_SIZE     4096
#define SEND_BUF_SIZE     4096

class ServerCommand
{
public:
	ServerCommand( int sockfd ) ;
	~ServerCommand( void ) ;
	int QuitCommand( void ) const ;
	int GetCommand( const char *fileName ) const ;
	int PutCommand( const char *fileName ) const ;
	int HelpCommand( void ) const ;
	int LsCommand( void ) const ;
	int CdCommand( const char *path ) ;
private:
	int     m_sockfd ;
	std::string  m_path ;
} ;

#endif // _COMMAND_H
