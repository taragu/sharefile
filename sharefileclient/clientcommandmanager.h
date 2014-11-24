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

  static void setClientCommand(ClientCommand * _clientCommand) {
    clientCommand = _clientCommand;
  }

//  static ClientCommand * getClientCommand() {
//      return clientCommand;
//  }

  ~ClientCommandManager( void )
  {
      delete clientCommand;
  }

};

#endif
