#ifndef SERVER_H
#define SERVER_H

#include "LinkedList.h"
#include <string>

class Server {
private:
    LinkedList list;

public:
    std::string handleRequest(const std::string& request);
};

#endif