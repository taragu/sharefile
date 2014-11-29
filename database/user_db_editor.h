#ifndef USER_DB_EDITOR_H
#define USER_DB_EDITOR_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>
#include <E:/551/sqlite-amalgamation-3080702/sqlite3.h>
#include <string>
#include <sstream>
#include <cstring>
#include <queue>
class user_db_editor
{
    int n;
    bool DbEditor(std::string s, sqlite3 * db);
    std::string DbGetAnswer(std::string s, int c,sqlite3 * db_user);
    std::string DbGetAnswerThenCloseDb(std::string s,int c, sqlite3 * db);
    bool user_db_editor::DbContain(std::string tablename, std::string col, std::string target, sqlite3 * db );
    int DbUGetID(std::string username, sqlite3 * db_user);
    //bool DbAddUser(int id, std::string username,std::string auth_token,std::string email, sqlite3 * db_user);
    int DbUGetSize(sqlite3 * db_user);
    int DbFGetSize(sqlite3 * db_file, std::string DbName);
    std::string UserDbGetF(int id, sqlite3 * db_user);
    //bool user_db_editor::DbContF(int id2, sqlite3 * db_frd );
public:
    user_db_editor();

    bool DbAddUser(std::string username,std::string auth_token,sqlite3 * db_user);
    std::string UserDbGetAt(std::string username, sqlite3 * db_user);
    int UserDbLogin(std::string username, std::string password, sqlite3 * db_user);
    std::string user_db_editor::DbGetPath( std::string username,  std::string FileName, sqlite3 * db_user);
    std::string user_db_editor::DbGetPathS( std::string username,  std::string FileName, sqlite3 * db_user);
    int user_db_editor::DbAddFriend(std::string username1, std::string username2, sqlite3 * db_user);
    bool user_db_editor::DbAddFileSToF( int user_id, int tofriend_id,std::string FileName, std::string path);
    bool user_db_editor::DbAddFileS( std::string username, std::string path, std::string FileName,std::string toFriend_name, sqlite3 * db_user);
    bool user_db_editor::DbAddFile( std::string username, std::string path,std::string FileName, sqlite3 * db_user);
    int DbInitialize(void);
    int DbFInitialize(std::string DbName);
    int DbFrInitialize(std::string DbName);
    int DbPrint(std::string DbName);//print database, for test

};

bool UserDbContF(int id,std::string friend_id );

#endif // USER_DB_EDITOR_H
