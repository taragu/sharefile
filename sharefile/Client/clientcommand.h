#ifndef _CLIENTCOMMAND_H
#define _CLIENTCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <dirent.h>

#include <iostream>

#define RECV_BUF_SIZE         4096
#define SEND_BUF_SIZE         4096

typedef struct sockaddr SA ;

#define COMMAND_LS            "ls"
#define COMMAND_CD            "cd"
#define COMMAND_GET           "get"
#define COMMAND_PUT           "put"
#define COMMAND_QUIT          "by"
#define COMMAND_HELP          "help"

class ClientCommand
{
public:
	ClientCommand( const char *ip, int port ) ;
	~ClientCommand( void ) ;
	int QuitCommand( void ) ;
	int GetCommand( const char *fileName ) const ;
	int PutCommand( const char *fileName ) const ;
	int HelpCommand( void ) const ;
	int LsCommand( void ) const ;
	int CdCommand( const char *path ) ;
	int manager( void ) ;
private:
	int  m_sockfd ; // socket
	bool m_bstart ; // server start sign
} ;

#endif // _CLIENTCOMMAND_H
