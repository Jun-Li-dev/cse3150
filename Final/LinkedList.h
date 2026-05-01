#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <memory>
#include <vector>
#include <string>

class LinkedList {
private:
    std::shared_ptr<Node> root;
    std::vector<std::shared_ptr<Node>> nodes; 

public:
    void SERVER_buildCircularLinkedList();
    void SERVER_deleteCircularLinkedList();

    std::string SERVER_printLinkedList();
    std::string CLIENT_printLinkedList();
};

#endif