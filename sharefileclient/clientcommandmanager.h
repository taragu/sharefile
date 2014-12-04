#ifndef _CLIENTCOMMANDMANAGER_H
#define _CLIENTCOMMANDMANAGER_H

#include "clientcommand.h"
#include <iostream>
#include <string>
#include <set>




class ClientCommandManager {

public:

    static ClientCommand * clientCommand;

    static void setClientCommand(ClientCommand * _clientCommand) {
        clientCommand = _clientCommand;
    }

    ~ClientCommandManager( void )
    {
        delete clientCommand;
    }

};

#endif
