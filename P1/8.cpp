#include <iostream>
#include "show-pset1.h"
using namespace std;


struct nodeP8 {
    char value;
    nodeP8 *next;
    bool deleted;

    nodeP8(char v) {
        value = v;
        next = NULL;
        deleted = false;
    }
};


static void insertNode(nodeP8 **head, char v) {
    nodeP8 *newnode = new nodeP8(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP8 *parent = NULL;
        nodeP8 *current = *head;
        while (current->next) {
            if (current->deleted) {
                if (current == *head) {
                    if ((*head)->next) {
                        nodeP8 *temp = (*head)->next;
                        delete *head;
                        *head = temp;
                    }
                    else {
                        head = NULL;
                        delete current;
                        *head = newnode;
                    }
                }
                else {
                    nodeP8 *temp = current->next;
                    parent->next = current->next;
                    current = temp;
                    delete current;
                }
            }

            parent = current;
            current = current->next;
        }
        current->next = newnode;
    }
}


static void delNode(nodeP8 *n) {
    if (n->next) {
        nodeP8 *curr = n->next;
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
    else {
        n->deleted = true;
    }
}


static void printList(nodeP8 *head) {
    while (head) {
        if (head->deleted == false) {
            cout << head->value << " -> ";
        }
        head=head->next;
    }
}

void showP8() {
    nodeP8 *first = NULL;

    insertNode(&first, 'a');
    insertNode(&first, 'b');
    insertNode(&first, 'c');
    insertNode(&first, 'd');

    delNode(first->next->next->next);

    printList(first);
}