#ifndef _LIST_H
#define _LIST_H

#include "node.h"
#include <iostream>

using namespace std;

class Linkedlist{
    
    Node* root;

    friend ostream & operator<<(ostream & os, const Linkedlist & linkedlist);

public:
    Linkedlist();
    Linkedlist(const Linkedlist& other);
    ~Linkedlist();

    void insertInFront(int _data);
    void deleteAt(int i);
    bool checkPrefixSum() const;
    void pointerJumping();
    void traverseList();
};

ostream & operator<<(ostream & os, const Node & node);

#endif