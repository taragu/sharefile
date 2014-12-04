#ifndef __DbAddUser_H__
#define __DbAddUser_H__

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <sstream>
#include "UserDbEditor.h"

bool DbAddUser(int id, std::string username,std::string auth_token,std::string email, sqlite3 * db_user)
{
    std::stringstream idss;
    idss<<id;
    /* Create SQL statement */
    std::string sql = "INSERT INTO UsersTable (id,username,auth_token,email) " \
                      "VALUES (";
    idss<<",'"<<username<<"','"<<auth_token<<"','"<<email<<"');";
    sql.append(idss.str());
    // sql.append(",'");

    UserDbEditor(sql, db_user);
    return 0;
}

#endif
