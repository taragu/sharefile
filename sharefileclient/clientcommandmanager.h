#ifndef _CLIENTCOMMANDMANAGER_H
#define _CLIENTCOMMANDMANAGER_H

#include "clientcommand.h"
#include <iostream>
#include <string>
#include <set>

class ClientCommandManager {
  ClientCommand * clientCommand;

public:
  static void createClientCommand(char * ip, int portnumber) {
    ClientCommand * _clientcommand = new ClientCommand( ip, portnumber) ;
    clientCommand = _clientCommand;
    _clientcommand->manager() ;
  }

  static ClientCommand * getClientCommand() {
      return clientCommand;
  }
};

#endif
