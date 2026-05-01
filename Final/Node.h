#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node {
    string name;
    weak_ptr<Node> next;

    Node(string name) : name{name} {}

    ~Node() {
        cout << "Node [" << name << "] destructor" << endl;
    }
};

#endif