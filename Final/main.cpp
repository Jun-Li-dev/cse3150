#include "Server.h"
#include "Client.h"

int main() {
    Server server;
    Client client(server);

    client.sendRequest("BUILD");
    client.sendRequest("SERVER_PRINT");
    client.sendRequest("CLIENT_PRINT");
    client.sendRequest("DELETE");
    client.sendRequest("CLIENT_PRINT");

    return 0;
}