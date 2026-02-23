#include<iostream>
#include "list.h"

using namespace std;

Linkedlist::Linkedlist() : root{nullptr} {}

Linkedlist::Linkedlist(const Linkedlist& other) : root{nullptr} {
    if (!other.root) return;

    root = new Node(other.root->data);
    Node* curr = root;
    Node* otherCurr = other.root->next;

    while (otherCurr) {
        curr->next = new Node(otherCurr->data);
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
}

void Linkedlist::insertInFront(int _data){
    Node* insertNode = new Node(_data);

    insertNode->next = root;        
    root = insertNode;
}

Linkedlist::~Linkedlist(){
    if(!root) return;

    Node* current = root;
    while(current){
        cout <<"in ~Linkedlist "
             << static_cast<void*>(current)<<" next: "
             << static_cast<void*>(current->next) << endl;

        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Linkedlist::deleteAt(int i){
    if(!root || i < 0) return;

    if(i == 0){
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }

    Node* current = root;
    for(int k = 0; k < i-1 && current->next; k++){
        current = current->next;
    }

    if(current->next){
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Prefix sum check
bool Linkedlist::checkPrefixSum() const {
    int sum = 0;
    Node* current = root;

    while(current){
        sum += current->data;
        if(sum < 0) return false;
        current = current->next;
    }
    return true;
}

void Linkedlist::pointerJumping(){
    Node* current = root;

    while(current && current->next){
        current->next = current->next->next;
        current = current->next;
    }
}

void Linkedlist::traverseList(){
    Node * current = root;
    while(current){
        cout << *current << " ";
        current = current->next;
    }
}

ostream & operator<<(ostream & os, const Node & node){
    os << node.data;
    return os;
}

ostream & operator<<(ostream & os, const Linkedlist & linkedlist){
    Node* traversal = linkedlist.root;
    while (traversal){
        os<< *traversal << " ";
        traversal = traversal->next;
    }
    return os;
}