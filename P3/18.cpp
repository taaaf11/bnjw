#include <iostream>
#include "show-pset3.h"
using namespace std;


struct nodeP18 {
    char value;
    nodeP18 *next;
    bool deleted;

    nodeP18(char v) {
        value = v;
        next = NULL;
        deleted = false;
    }
};



static void insertNode(nodeP18 **head, char v) {
    nodeP18 *newnode = new nodeP18(v);
    if (*head == NULL) {
        *head = newnode;
    }

    else {
        nodeP18 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static void delNode(nodeP18 *n) {
    if (n->next == NULL) {
        throw runtime_error("Node not in middle of list.");
    }

    nodeP18 *curr = n->next;
    while (curr) {
        // this will occur when curr is last node
        // then, n will be second last node.
        // we delete the curr node, and set n->next to NULL.
        if (curr->next == NULL) {
            // cout << "curr next null occured" << endl;
            delete curr;
            n->next = NULL;
        }

        // else, we copy values from next nodes
        // to currents nodes.
        n->value = curr->value;

        n = n->next;
        curr = curr->next;
    }
}

static void printList(nodeP18 *head) {
    while (head) {
        if (head->deleted == false) {
            cout << head->value << " -> ";
        }
        head=head->next;
    }
}

void showP18() {
    nodeP18 *first = NULL;
    
    insertNode(&first, 'a');
    insertNode(&first, 'b');
    insertNode(&first, 'c');
    insertNode(&first, 'd');
    insertNode(&first, 'e');

    cout << "original: ";
    printList(first);
    
    delNode(first->next->next);

    cout << endl << "After deleting c: ";
    printList(first);
}