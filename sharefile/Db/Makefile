CFLAGS= -Wall -Werror -std=gnu++98 -pedantic -ggdb3
SOURCES=test.cpp
OBJS=$(patsubst %.cpp, %.o,$(SOURCES))

all: DatabasePrint DbAddUser test

test: $(OBJS)
	g++ $(CFLAGS) -o test $(OBJS) -l sqlite3
%.o: %.cpp UserDbEditor.h DbInitialize.h DbAddUser.h
	g++ $(CFLAGS) -c $<

DatabaseInitialize: DatabaseInitialize.cpp
	g++ $(CFLAGS) -o DatabaseInitialize DatabaseInitialize.cpp -l sqlite3

DatabasePrint: DatabasePrint.cpp
	g++ $(CFLAGS) -o DatabasePrint DatabasePrint.cpp -l sqlite3

DbAddUser: DbAddUser.cpp
	g++ $(CFLAGS) -o DbAdduser DbAddUser.cpp -l sqlite3



clean:
	rm  DatabaseInitialize DatabasePrint *~