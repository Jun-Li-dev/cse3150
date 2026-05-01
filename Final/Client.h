#ifndef CLIENT_H
#define CLIENT_H

#include "Server.h"
#include <string>

class Client {
private:
    Server& server;

public:
    Client(Server& srv);
    void sendRequest(const std::string& request);
};

#endif