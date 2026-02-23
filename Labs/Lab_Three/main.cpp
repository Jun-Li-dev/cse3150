#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.h"

TEST_CASE("Insert and print list") {
    Linkedlist list;

    list.insertInFront(1);
    list.insertInFront(2);
    list.insertInFront(3); // 3 2 1

    CHECK(list.checkPrefixSum() == true);
}

TEST_CASE("Delete ith node") {
    Linkedlist list;

    list.insertInFront(3);
    list.insertInFront(2);
    list.insertInFront(1); // 1 2 3

    list.deleteAt(1); // remove 2

    CHECK(list.checkPrefixSum() == true);
}

TEST_CASE("Copy constructor") {
    Linkedlist list;
    list.insertInFront(1);
    list.insertInFront(2);
    list.insertInFront(3);

    Linkedlist copy(list);

    CHECK(copy.checkPrefixSum() == true);
}

TEST_CASE("Prefix sum positive") {
    Linkedlist list;
    list.insertInFront(3);
    list.insertInFront(-1);
    list.insertInFront(2); // 2 -1 3

    CHECK(list.checkPrefixSum() == true);
}

TEST_CASE("Prefix sum negative") {
    Linkedlist list;
    list.insertInFront(-5);
    list.insertInFront(2); // 2 -5

    CHECK(list.checkPrefixSum() == false);
}

TEST_CASE("Pointer jumping") {
    Linkedlist list;
    list.insertInFront(4);
    list.insertInFront(3);
    list.insertInFront(2);
    list.insertInFront(1); // 1 2 3 4

    list.pointerJumping(); // should become 1 3

    CHECK(list.checkPrefixSum() == true);
}