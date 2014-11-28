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
    qmake -project && qmake sharefileclient.pro && make && ./sharefileclient
