#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "UserDbEditor.h"
#include "DbInitialize.h"
#include "DbAddUser.h"
#include <string>
int main(int argc, char* argv[])
{
    //Initialize and open databases
    sqlite3 * db_user;
    sqlite3 * db_file;
    DbInitialize();
    sqlite3_open("UsersTable.db", &db_user);
    sqlite3_open("FilesTable.db", &db_file);

    /* Create SQL statement */
    std::string sql = "INSERT INTO UsersTable (id,username,auth_token,email,friend_id) " \
                      "VALUES (2, 'Ah', 'abc', 'Ahhh@Ah.com', '2,3,' ); ";
    \
    UserDbEditor(sql, db_user);
    DbAddUser(1, "Oh", "def", "OOOO@oh.com", db_user);
    //close databases
    sqlite3_close(db_user);
    sqlite3_close(db_file);

    return 1;
}
