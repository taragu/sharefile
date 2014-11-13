#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include "UserDbEditor.h"
#include <string>
int main(int argc, char* argv[])
{
  /* Create SQL statement */
  std::string sql = "INSERT INTO UsersTable (id,username,auth_token,email,friend_id) " \
     "VALUES (2, 'Ah', 'abc', 'Ahhh@Ah.com', '2,3,' ); ";	\
  UserDbEditor(sql);
   return 0;
}
