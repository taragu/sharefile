#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <E:/551/sqlite-amalgamation-3080702/sqlite3.h>
//#include "UserDbEditor.h"
//#include "DbInitialize.h"
//#include "DbAddUser.h"
#include "user_db_editor.h"
#include <string>
#include <QObject>
//#include <QSqlDatabase>
//#include <QSqlError>
#include <QFile>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Initialize and open databases
    sqlite3 * db_user;
    sqlite3 * db_file;
    user_db_editor ude;
    ude.user_db_editor::DbInitialize();
    sqlite3_open("UsersTable.db", &db_user);
    sqlite3_open("FilesTable.db", &db_file);

    /* Create SQL statement */
    /*std::string sql = "INSERT INTO UsersTable (id,username,auth_token,email,friend_id) " \
        "VALUES (2, 'Ah', 'abc', 'Ahhh@Ah.com', '2,3,' ); ";		\
        */
    std::string sql = "INSERT INTO UsersTable (id,username,auth_token,friend_id) " \
        "VALUES (2, 'Ah', 'abc',  '2,3,' ); ";
    ude.user_db_editor::UserDbEditor(sql, db_user);

    ude.user_db_editor::DbAddUser(1, "Oh", "def",  db_user);
    //close databases
    std::cout<<ude.user_db_editor::DbGetSize(db_user);
    ude.user_db_editor::UserDbSelectName("a", db_user);
    ude.user_db_editor::UserDbSelectName("Ah", db_user);
    sqlite3_close(db_user);
    sqlite3_close(db_file);
    ude.user_db_editor::DbPrint();
    return a.exec();
}
