Server: main.cpp servercommand.cpp user_db_editor.cpp 
	g++ -ggdb3 -Wall -Werror -pedantic -pthread -o Server main.cpp servercommand.cpp user_db_editor.cpp -l sqlite3
databasetest: databasetest.cpp 	user_db_editor.cpp 
	g++ -ggdb3 -Wall -Werror -pedantic -pthread -o databasetest databasetest.cpp user_db_editor.cpp -l sqlite3
clean:
	rm Server *~
