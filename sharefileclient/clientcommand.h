#ifndef _CLIENTCOMMAND_H
#define _CLIENTCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <dirent.h>

#include <iostream>
#include <string>
#include <set>

using namespace std ;

#define RECV_BUF_SIZE         4096
#define SEND_BUF_SIZE         4096
#define MSG_BUF_SIZE          256


typedef struct sockaddr SA ;

#define COMMAND_LS            "ls"
#define COMMAND_LSF           "fls"
#define COMMAND_LSM           "mls"
#define COMMAND_CD            "cd"
#define COMMAND_GET           "get"
#define COMMAND_PUT           "put"
#define COMMAND_QUIT          "by"
#define COMMAND_HELP          "help"
#define COMMAND_LOGIN         "login"
#define COMMAND_LOGON         "logon"
#define COMMAND_SHARE         "share"
#define COMMAND_RM            "rm"
#define COMMAND_SEND          "send"
#define COMMAND_UN            "un"
#define COMMAND_AP            "ap"


class ClientCommand
{
public:
    ClientCommand( const char *ip, int port ) ;
    ~ClientCommand( void ) ;
    int QuitCommand( void ) ;
    int GetCommand( string file, string localpath = "" ) const ;
    int PutCommand( string fileName ) const ;
    int HelpCommand( void ) const ;
//    int LsCommand( void ) const ;
//    int LsfCommand( void ) const ;
//    int LsmCommand( void ) const;
    int CdCommand( string path ) ;
//    int LoginCommand( void ) ;
//    int LogonCommand( void ) ;
    int ShareCommand( string file, string user ) ;
    int RmCommand( string strfilename ) ;
    int SendCommand(string user, string msg) ;
    int manager( void ) ;
    int ApCommand(string _name);
    int UnCommand(string __name);

    std::set<std::string> LsfCommand( void ) const ;
    std::set<std::string> LsmCommand( void ) const;
    std::set<std::string> LsCommand( void ) const ;

    int LoginCommand( std::string username, std::string password ) ;
    int LogonCommand( std::string username, std::string password ) ;

    std::string getUsername();
    // send yuzhou friend_request
    // send yuzhou howareyou
private:
    struct UserMsg
    {
        char sender[256];
        char message[MSG_BUF_SIZE];
    };

    struct UserData
    {
        char username[256] ;
        char password[256] ;
        UserData( const std::string &name = "",
                  const std::string &passwd = "" )
        {
            strcpy( username, name.c_str() ) ;
            strcpy( password, passwd.c_str() ) ;
        }
        bool operator<( const UserData &that ) const
        {
            return strcmp( username, that.username ) < 0 ;
        }
    } ;
    int  m_sockfd ;   // socket
    bool m_bstart ;   // server status
    UserData m_user ; // user info
} ;

#endif //
