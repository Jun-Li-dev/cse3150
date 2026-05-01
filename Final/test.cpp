#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Server.h"

TEST_CASE("Build and Server Print") {
    Server server;

    std::string result = server.handleRequest("BUILD");
    CHECK(result.find("built") != std::string::npos);

    result = server.handleRequest("SERVER_PRINT");

    CHECK(result.find("[zero]") != std::string::npos);
    CHECK(result.find("[one]") != std::string::npos);
    CHECK(result.find("[two]") != std::string::npos);
    CHECK(result.find("[three]") != std::string::npos);
    CHECK(result.find("[four]") != std::string::npos);
    CHECK(result.find("[five]") != std::string::npos);
}

TEST_CASE("Client print before delete") {
    Server server;

    server.handleRequest("BUILD");

    std::string result = server.handleRequest("CLIENT_PRINT");

    CHECK(result.find("[zero]") != std::string::npos);
    CHECK(result.find("[five]") != std::string::npos);
    CHECK(result.find("Yipes!") == std::string::npos);
}

TEST_CASE("Client print after delete") {
    Server server;

    server.handleRequest("BUILD");
    server.handleRequest("DELETE");

    std::string result = server.handleRequest("CLIENT_PRINT");

    CHECK(result.find("Yipes!") != std::string::npos);
}