.PHONY: all testclient testserver

all: testclient testserver

testclient: client.cpp
	g++ -ggdb3 -Wall -Werror -pedantic -o testclient client.cpp 
testserver: server.cpp
	g++ -ggdb3 -Wall -Werror -pedantic -o testserver server.cpp 
clean:
	rm testclient testserver *~