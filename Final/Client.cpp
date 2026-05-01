#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(Server& srv) : server(srv) {}

void Client::sendRequest(const string& request) {
    cout << "\nClient request: " << request << endl;

    string response = server.handleRequest(request);

    cout << response << endl;
}