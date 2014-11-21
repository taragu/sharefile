#ifndef __DbInitialize_H__
#define __DbInitialize_H__
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
/*
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}
*/
int DbInitialize(void)
{
  sqlite3 * db_user;
  sqlite3 * db_file;
  char *zErrMsg = 0;
  int  rc_user, rc_file;
  /* Open database */
  rc_user = sqlite3_open("UsersTable.db", &db_user);
  rc_file = sqlite3_open("FilesTable.db", &db_file);
    
if( rc_user ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_user));
    exit(0);
  }else{
    fprintf(stdout, "Opened database successfully\n");
  }

if( rc_file ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_file));
    exit(0);
  }else{
    fprintf(stdout, "Opened database successfully\n");
  }

  //Create SQL statement 
   const char * sql_user = "CREATE TABLE UsersTable("  \
         "id INT PRIMARY KEY     NOT NULL," \
         "username           TEXT    NOT NULL," \
         "auth_token         TEXT     NOT NULL," \
         "email              TEXT    NOT NULL,"\
         "friend_id          TEXT," \
         "created_at         DATETIME ,"\
         "updated_at         DATETIME  );";

   const char * sql_file = "CREATE TABLE FilesTable(" \
         "id INT PRIMARY KEY     NOT NULL," \
         "user_id          INT   NOT NULL," \
         "path             TEXT  NOT NULL,"\
         "accessibility    INT     NOT NULL," \
         "created_at       DATETIME," \
         "updated_at       DATETIME );";


   /* Execute SQL statement */
   rc_user = sqlite3_exec(db_user, sql_user, callback, 0, &zErrMsg);
   rc_file = sqlite3_exec(db_user, sql_file, callback, 0, &zErrMsg);
   if( rc_user != SQLITE_OK || rc_file != SQLITE_OK){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
   }else{
     fprintf(stdout, "Tables created successfully\n");
   }
   sqlite3_close(db_user);
   sqlite3_close(db_file);
   return 1;
}

#endif
