#include "Server.h"
#include <sstream>

using namespace std;

string Server::handleRequest(const string& request) {
    stringstream response;

    if (request == "BUILD") {
        list.SERVER_buildCircularLinkedList();
        response << "Server: List built\n";
    }
    else if (request == "SERVER_PRINT") {
        response << list.SERVER_printLinkedList();
    }
    else if (request == "CLIENT_PRINT") {
        response << list.CLIENT_printLinkedList();
    }
    else if (request == "DELETE") {
        list.SERVER_deleteCircularLinkedList();
        response << "Server: List deleted\n";
    }
    else {
        response << "Unknown request\n";
    }

    return response.str();
}