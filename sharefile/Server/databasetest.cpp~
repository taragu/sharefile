
//#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sqlite3.h>
//#include "UserDbEditor.h"
//#include "DbInitialize.h"
//#include "DbAddUser.h"
#include "user_db_editor.h"
#include <string>
//#include <QObject>
//#include <QSqlDatabase>
//#include <QSqlError>
//#include <QFile>
int main(int argc, char *argv[])
{
  //QCoreApplication a(argc, argv);

    //Initialize and open databases
    sqlite3 * db_user;
    //sqlite3 * db_file;
    user_db_editor ude;
    ude.user_db_editor::DbInitialize();
    sqlite3_open("UsersTable.db", &db_user);
    //sqlite3_open("FilesTable.db", &db_file);

    /* Create SQL statement */
    /*std::string sql = "INSERT INTO UsersTable (id,username,auth_token,email,friend_id) " \
        "VALUES (2, 'Ah', 'abc', 'Ahhh@Ah.com', '2,3,' ); ";		\
        */
    ude.user_db_editor::DbAddUser("Ah", "def",  db_user);
    ude.user_db_editor::DbAddUser("Bee", "abc",  db_user);
    ude.user_db_editor::DbAddUser("Bee", "edc",  db_user);
    ude.user_db_editor::DbAddUser("Cece", "123",  db_user);

    ude.user_db_editor::UserDbLogin("Ah", "def", db_user);
    ude.user_db_editor::UserDbLogin("Bee", "rfv", db_user);
    ude.user_db_editor::UserDbLogin("Ce", "def", db_user);
    ude.DbAddFriend("Ah", "Bee", db_user);
    ude.DbAddFriend("Ah", "Bee", db_user);
    ude.DbAddFriend("Ah", "Cece", db_user);
    ude.DbAddMessage("Ah", "Bee", 0,"Hi!",db_user);

    //close databases
    //std::cout<<ude.user_db_editor::DbGetSize(db_user);
    //ude.user_db_editor::UserDbSelectName("a", db_user);
    //std::cout<<ude.user_db_editor::UserDbSelectName("No", db_user);

    ude.user_db_editor::DbAddFileS( "Ah", "path1","File1", "Bee", db_user);
    ude.user_db_editor::DbAddFileS( "Ah", "path1","File1", "Bee", db_user);
    ude.user_db_editor::DbAddFile( "Bee", "pathB", "FileB", db_user);
    ude.user_db_editor::DbAddFile( "Bee", "pathB", "FileB", db_user);
    std::cout<<"File1's path"<<ude.user_db_editor::DbGetPath("Ah",  "File1", db_user)<<std::endl;
    std::cout<<"File1's path"<<ude.user_db_editor::DbGetPathS("Bee",  "File1", db_user)<<std::endl;
    ude.user_db_editor::DbGetFrQ("Ah",db_user);
    ude.user_db_editor::DbRmFriend("Ah","CeCe",db_user);

    sqlite3_close(db_user);
    //sqlite3_close(db_file);
    ude.user_db_editor::DbPrint("UsersTable");
    ude.user_db_editor::DbPrint("user1F");
    ude.user_db_editor::DbPrint("user1FilesTable");
    ude.user_db_editor::DbPrint("user1FilesTableS");
    ude.user_db_editor::DbPrint("user2F");
    ude.user_db_editor::DbPrint("user2FilesTable");
    ude.user_db_editor::DbPrint("user2FilesTableS");
    ude.user_db_editor::DbPrint("user1FilesTableSMessage");
    return 1;
    //return a.exec();
}
