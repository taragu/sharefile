#ifndef _CLIENTCOMMANDMANAGER_H
#define _CLIENTCOMMANDMANAGER_H

#include "clientcommand.h"
#include <iostream>
#include <string>
#include <set>




class ClientCommandManager {

    //ClientCommand * clientCommand;
public:

  static ClientCommand * clientCommand;

//  static void createClientCommand(char * ip, int portnumber) {
//    clientCommand = new ClientCommand( ip, portnumber) ;
//    clientCommand->manager() ;
//  }

//  static ClientCommand * getClientCommand() {
//      return clientCommand;
//  }
};

#endif
