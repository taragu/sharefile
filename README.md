#sharefile

##Installing Qt binary packages

###Ubuntu
    sudo apt-get install qt4-qmake
    sudo apt-get install libqt4-dev

    qmake -project && qmake hello.pro && make && ./hello
