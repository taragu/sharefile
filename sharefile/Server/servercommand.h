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
#include <sys/stat.h>

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

#include "user_db_editor.h"
#include <sqlite3.h>

using namespace std ;

#define COMMAND_QUIT      "by"
#define COMMAND_GET       "get"
#define COMMAND_HELP      "help"
#define COMMAND_PUT       "put"
#define COMMAND_LS        "ls"
#define COMMAND_CD        "cd"
#define COMMAND_LOGIN     "login"
#define COMMAND_LOGON     "logon"
#define COMMAND_SHARE     "share"
#define COMMAND_RM        "rm"
#define COMMAND_SEND      "send"
#define COMMAND_LSM       "mls"
#define COMMAND_LSF       "fls"

#define RECV_BUF_SIZE     4096
#define SEND_BUF_SIZE     4096
#define MSG_BUF_SIZE      4096

class ServerCommand
{
 public:
  ServerCommand( int sockfd ) ;
  ~ServerCommand( void ) ;
  int QuitCommand( void ) const ;
  int GetCommand( const char *fileName ) const ;
  int PutCommand( const char *fileName ) const ;
  int LsCommand( void ) const ;
  int LsmCommand( void )  ;
  int LsfCommand( void )  ;
  
  // int LsmCommand( void )  ;
  // int LsfCommand( void )  ;

  int CdCommand( const char *path ) ;
  int HelpCommand( void ) const ;
  int LoginCommand( void ) ;   // login on 
  int LogonCommand( void ) ;   // register
  int ShareCommand( void ) ;  // share
  int RmCommand( string filename ) ; // delete
  int SendCommand( void ); // send request or message
  bool ApproveAddFriendCommand(string Name2);//add friend
  bool RemoveFriendCommand(std::string receivername);
  
  //database
  sqlite3 * db_user;
   user_db_editor ude;
 private:
  struct UserData
  {
    UserData( const string &name = "",
	      const string &passwd = "" )
    {
      strcpy( username, name.c_str() ) ;
      strcpy( password, passwd.c_str() ) ;
    }
    char username[256] ;
    char password[256] ;
    bool operator<( const UserData &that ) const
    {
      return strcmp( username, that.username ) < 0 ;
    }
  } ;

  struct UserMsg
  {
    char sender[256];
    char message[MSG_BUF_SIZE];
  };


  bool           m_bstart ;     // server status
  int            m_sockfd ;     // socket
  string         m_userpath ;   // user directory
  string         m_serverpath ; // server directory
  string         m_username ;   // user
  string         m_password ;   // password
  //  int            m_fd ;         // user data file
  set<UserData>  m_Datas ;      // user data
 private:
  //user not found
  bool FindUser( const string &name ) const ;   
} ;

template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif 
