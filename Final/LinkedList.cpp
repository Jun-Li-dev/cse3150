#include "LinkedList.h"
#include <sstream>

using namespace std;

void LinkedList::SERVER_buildCircularLinkedList() {
    vector<string> names = {"zero","one","two","three","four","five"};

    nodes.clear();

    root = make_shared<Node>(names[0]);
    nodes.push_back(root);

    shared_ptr<Node> node = root;

    for (int i = 1; i < names.size(); i++) {
        auto newNode = make_shared<Node>(names[i]);

        nodes.push_back(newNode);   // keep pointing
        node->next = newNode;       

        node = newNode;
    }

    node->next = root; 
}

// server print things
string LinkedList::SERVER_printLinkedList() {
    stringstream out;

    if (!root) {
        out << "[Nothing]\n";
        return out.str();
    }

    shared_ptr<Node> current = root;

    for (int i = 0; i < 6; i++) {

        out << "[" << current->name << "]";
        out << " : use_count: " << current.use_count();
        out << " address: " << current.get();

        auto nextNode = current->next.lock();

        out << " next (from shared_ptr): ";
        out << (nextNode ? nextNode.get() : 0) << "\n";

        if (!nextNode) break;

        current = nextNode;
    }

    return out.str();
}

// client print stuff
string LinkedList::CLIENT_printLinkedList() {
    stringstream out;

    vector<string> names = {"zero","one","two","three","four","five"};

    shared_ptr<Node> current = root;

    for (int i = 0; i < names.size(); i++) {

        out << "[" << names[i] << "]";

        if (current) {
            out << " : use_count: " << current.use_count();
            out << " address: " << current.get();
        }

        auto nextNode = current ? current->next.lock() : nullptr;

        out << " next (from weak_ptr): ";

        if (nextNode) {
            out << nextNode.get() << "\n";
            current = nextNode;
        } else {
            out << "0\n";
            out << "Yipes! shared_ptr not available\n";
            current = nullptr;
        }
    }

    return out.str();
}

// delete
void LinkedList::SERVER_deleteCircularLinkedList() {
    cout << "\nServer is deleting the shared_ptrs\n" << endl;

    for (auto& n : nodes) {
        n->next.reset();
    }

    nodes.clear(); //destory stuff
    root.reset();  
}