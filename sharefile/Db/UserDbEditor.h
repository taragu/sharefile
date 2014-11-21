#ifndef __UserDbEditor_H__
#define __UserDbEditor_H__
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>
/*bool UserDbEditor(std::string s){}*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

bool UserDbEditor(std::string s, sqlite3 * db_user)
{
  //sqlite3 *db_user;
  char *zErrMsg = 0;
  int rc;
  

  /* Open database 
  rc = sqlite3_open("UsersTable.db", &db_user);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_user));
    exit(0);
  }
 else{
    fprintf(stderr, "Opened database successfully\n");
  }

  */
   /* Execute SQL statement */
  rc = sqlite3_exec(db_user, s.c_str(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
   }else{
     fprintf(stdout, "%s successfully\n", s.c_str());
   }
   //sqlite3_close(db_user);
   return 1;
}


#endif
