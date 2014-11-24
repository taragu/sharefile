#ifndef USER_DB_EDITOR_H
#define USER_DB_EDITOR_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>
#include <E:/551/sqlite-amalgamation-3080702/sqlite3.h>
#include <string>
#include <sstream>
class user_db_editor
{
    int n;
public:
    user_db_editor();
    bool UserDbEditor(std::string s, sqlite3 * db_user);
    std::string UserDbEditorAnswer(std::string s, int c,sqlite3 * db_user);
    bool UserDbSelectName(std::string username, sqlite3 * db_user);
    //bool DbAddUser(int id, std::string username,std::string auth_token,std::string email, sqlite3 * db_user);
    int DbGetSize(sqlite3 * db_user);
    bool DbAddUser(int id, std::string username,std::string auth_token,sqlite3 * db_user);
    int DbInitialize(void);
    int DbPrint(void);

};

#endif // USER_DB_EDITOR_H
