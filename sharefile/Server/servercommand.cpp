#include "servercommand.h"
#include "user_db_editor.h"
#include <sqlite3.h>
#include <sstream>
#define END 1234
using namespace std ;


ServerCommand::ServerCommand( int sockfd ) :
    db_user(NULL), m_sockfd( sockfd ), m_bstart(false),
    ude()
{
    m_serverpath = "." ;
    //  m_fd = open( "userdata.dat", O_CREAT | O_RDWR, 0644 ) ;
    //  if ( -1 == m_fd )
    // {
    //   perror( "open" ) ;
    // }

    UserData data ;
    memset( &data, 0, sizeof(data) ) ;
    //  while ( read( m_fd, &data, sizeof(data) ) > 0 )
    // {
    //   m_Datas.insert( data ) ;
    // }


    sqlite3_open("UsersTable.db", &db_user);
    m_bstart = true ;
}

ServerCommand::~ServerCommand( void )
{
    if ( !m_bstart )
    {
        return ;
    }
    //  close( m_fd ) ;
    close( m_sockfd ) ;
    sqlite3_close(db_user);
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

//list of message
//int ServerCommand::LsmCommand ( ) const
int ServerCommand::LsmCommand ( )

{

    // To be done by database
    // I guess it's looking into database and get the result
    // this class has fields like m_username that might be useful
    // you can check the header file
    int retval = 0;
    UserMsg userMsg;
    std::string username=m_username;
    bzero(userMsg.sender, sizeof(userMsg.sender));
    bzero(userMsg.message, sizeof(userMsg.message));
    queue<message_t> MQ;
    MQ=ude.user_db_editor::DbGetMessageQ(username, db_user);
    //std::cout<<"MQ"<<(MQ.front()).isRequest<<(MQ.front()).name<<(MQ.front()).message<<std::endl;
    while(!MQ.empty()) {
        stringstream MQs;
        MQs<<(MQ.front()).isRequest<<" "<<(MQ.front()).name<<" "<<(MQ.front()).message << endl;
        strcpy(userMsg.sender, MQ.front().name.c_str());
        strcpy(userMsg.message, MQ.front().message.c_str());
        if( write( m_sockfd, &userMsg, sizeof(userMsg)) < 0)
        {
            perror( "write" ) ;
            goto error;
        }
        // cout <<"( " <<userMsg.sender <<" ) " <<userMsg.message<< endl ;
        cout << MQs.str();
        MQ.pop();
        bzero(userMsg.sender, sizeof(userMsg.sender));
        bzero(userMsg.message, sizeof(userMsg.message));
    }
    *(int*)&userMsg = END ;
    write( m_sockfd, &userMsg, sizeof(userMsg) ) ;

    //    cout<< " done tshi command" << endl;
done:
    return retval;
error:
    retval = -1 ;
    goto done;

}

//int ServerCommand::LsfCommand ( ) const
int ServerCommand::LsfCommand ( )

{
    int retval = 0;

    // see above
    queue<string> FQ;
    FQ=ude.user_db_editor::DbGetFrQ(m_username, db_user);
    char sendBuf[SEND_BUF_SIZE] = { 0 } ;
    while(!FQ.empty()) {
        memset( sendBuf, 0, SEND_BUF_SIZE ) ;
        strcpy( sendBuf, FQ.front().c_str() ) ;
        write( m_sockfd, sendBuf, SEND_BUF_SIZE ) ;
        cout << FQ.front() << endl;
        FQ.pop();
    }
    *(int*)sendBuf = END ;
    write( m_sockfd, sendBuf, SEND_BUF_SIZE ) ;
done:
    return retval;
error:
    retval = -1 ;
    goto done;
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
        //      cout << "rbyte:" << rbyte << endl ;
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
    //  set<UserData>::iterator it ;
    if ( read( m_sockfd, &user, sizeof(user) ) < 0 )
    {
        perror( "read" ) ;
        goto error ;
    }
    cout << user.username << endl ;
    cout << user.password << endl ;
    //  it = m_Datas.find( user ) ;
    /*if ( m_Datas.end() != it )
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
    */
    if( ude.user_db_editor::UserDbLogin(user.username , user.password ,  db_user)) {
        replay=0;
    }
    else {
        replay=-1;
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
    m_username = user.username ;
    m_password = user.password ;
    m_userpath = m_serverpath + "/" + user.username ;
done:
    return retval ;
error:
    retval = -1 ;
    goto done ;
}

// register
int ServerCommand::LogonCommand( void )
{
    int retval = 0 ;
    UserData user ;
    memset( &user, 0, sizeof(user) ) ;
    int replay = 0 ;
    int trycount = 3 ;
    //  set<UserData>::iterator it ;
retry:
    if ( read( m_sockfd, &user, sizeof(user) ) < 0 )
    {
        perror( "read" ) ;
        goto error ;
    }
    cout << user.username << endl ;
    cout << user.password << endl ;
    //  it = m_Datas.find( user ) ;
    /*if ( m_Datas.end() == it )
      {
        m_Datas.insert( user ) ;
        replay = 0 ;
      }
    else
      {
        replay = -1 ;
      }

      */
    if (ude.user_db_editor::DbAddUser(user.username , user.password ,  db_user)) {
        replay=0;
    }
    else {
        replay=-1;
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
    m_username = user.username ;
    m_password = user.password ;
    m_userpath = m_serverpath + "/" + user.username ;
    cout << "m_userpath" << m_userpath << endl;
    if ( -1 == mkdir( m_userpath.c_str(), 0775 ) )
    {
        perror( "mkdir" ) ;
        goto error ;
    }
    // m_Datas.insert( user ) ;
    //  if ( write( m_fd, &user, sizeof(user) ) < 0 )
    // {
    //   perror( "m_userfile.write" ) ;
    //   goto error ;
    //  }
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

int ServerCommand::SendCommand( void )
{
    cout << "COMMAND_SEND" << endl;
    int retval = 0 ;
    char user[256] ;
    char message[256];
    bzero( user, sizeof(user));
    bzero( message, sizeof(message ) );
    // get receiver and message
    if ( read( m_sockfd, user, sizeof(user)) < 0 )
    {
        perror("read username" );
        goto error;
    }
    if (read( m_sockfd, message, sizeof(message) ) < 0 )
    {
        perror( " read message" );
        goto error;
    }

    //
    // DATABASE TO BE DONE
    //
    //
    //string users=user;
    //string messages=message;
    bool isRequest;
    if(strcmp(message,"friend_request")==0) {
        isRequest=1;
    }
    else {
        isRequest=0;
    }
    ude.DbAddMessage(user, m_username,isRequest, message, db_user);
    cout << message << endl;


done:
    cout << " COMMAND_SEND END" << endl ;
    return retval;
error:
    retval = -1 ;
    goto done;

}


int ServerCommand::ApCommand() {
    int retval = 0;
    char frdname[MSG_BUF_SIZE];
    int replay = 0;
    bzero( frdname, sizeof(frdname));

    if( read( m_sockfd, frdname, sizeof(frdname)) < 0 )
    {
        perror( " read friend name " );
        goto error;
    }

    if( !(ude.user_db_editor::DbAddFriend(m_username, frdname, db_user) &&
            ude.user_db_editor::DbAddFriend(frdname, m_username, db_user)))
    {
        perror("database failed");
        replay = -1;
    }
    if( write( m_sockfd, &replay, sizeof(replay)) < 0 )
    {
        perror("write");
        goto error;
    }


done:
    return retval;
error:
    retval = -1 ;
    goto done;

}


int ServerCommand::UnCommand() {
    int retval = 0;
    int replay = 0;
    char frdname[256];
    bzero( frdname, sizeof(frdname));
    //  cout<< "before reading friendname" << endl;
    if( read( m_sockfd, frdname, sizeof(frdname)) < 0 )
    {
        perror( " read friend name " );
        goto error;
    }
    //cout << " before database actions" << endl;
    if(!( ude.user_db_editor::DbRmFriend(m_username, frdname, db_user) &&
            ude.user_db_editor::DbRmFriend(frdname,m_username, db_user)))
    {
        perror("database failed");
        replay = -1 ;
    }


    //cout<< "before write replay" << endl;

    if(write(m_sockfd, &replay, sizeof(replay)) < 0 )
    {
        perror("write");
        goto error;
    }

done:
    return retval;
error:
    retval = -1;
    goto done;
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
