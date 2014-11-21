#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string>

static int callback(void *data, int argc, char **argv, char **azColName){
  int i;
  fprintf(stderr, "%s: ", (const char*)data);
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char* argv[])
{
  sqlite3 *db_user;
  sqlite3 *db_file;
  char *zErrMsg = 0;
  int rc;
  
  const char* data = "Callback function called";
  /* Open database */
  rc = sqlite3_open("UsersTable.db", &db_user);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_user));
    exit(0);
  }
  else{
    fprintf(stderr, "Opened database successfully\n");
  }


  /* Create merged SQL statement */
  /*  sql = "DELETE from COMPANY where ID=2; "	*/
  std::string sql = "SELECT * from UsersTable";

   /* Execute SQL statement */
  rc = sqlite3_exec(db_user, sql.c_str(), callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
     /*sqlite3_free(zErrMsg);*/
   }
   else{
     fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db_user);


  /* Open database */
  rc = sqlite3_open("FilesTable.db", &db_file);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_file));
    exit(0);
  }
  else{
    fprintf(stderr, "Opened database successfully\n");
  }


  /* Create merged SQL statement */
  /*  sql = "DELETE from COMPANY where ID=2; "	*/
  sql = "SELECT * from FilesTable";

   /* Execute SQL statement */
  rc = sqlite3_exec(db_file, sql.c_str(), callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
   }
   else{
     fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db_file);
    

 return 0;
}
