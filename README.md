#sharefile

Checkout our git repository at https://github.com/taragu/sharefile. 

##Installing Qt binary packages

###Ubuntu

	sudo apt-get install qt4-qmake
    	sudo apt-get install libqt4-dev

##Installing sqlite packages

	sudo apt-get install sqlite3
	sudo apt-get install libsqlite3-dev
    
####Start the Server

	cd sharefile/sharefile/Server
    	make
    	./Server <port number>
    
####Start the Client

	cd sharefile/sharefileclient

Open the Makefile (sharefile/sharefileclient/Makefile), and edit line 20, 21, and 24 with the path of your qmake binary, then cd into the directory sharefile/sharefileclient

Note: if you're running make in Qt Creator, PLEASE disable "shadow build"! (Go to Projects in the toolbar on the left, then uncheck the "Shadow Build" box).

	qmake -project 
	qmake sharefileclient.pro 
	make 
	./sharefileclient

####Note
- For uploading files, sharefile can support up to 1.5MB for each file.
- Valgrind: there was no memory leak when we run Valgrind in Qt Creator. However, if we run Valgrind in the terminal, there are many memory issues that come from the Qt Library. We could not figure out why.