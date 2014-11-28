#sharefile

##Installing Qt binary packages

###Ubuntu

	sudo apt-get install qt4-qmake
    	sudo apt-get install libqt4-dev
    
####Start the Server

	cd sharefile/sharefile/Server
    	make
    	./Server <port number>
    
####Start the Client
Open the Makefile (sharefile/sharefileclient/Makefile), and edit line 20, 21, and 24 with the path of your qmake binary, then cd into the directory sharefile/sharefileclient

	qmake -project 
	qmake sharefileclient.pro 
	make 
	./sharefileclient
    
