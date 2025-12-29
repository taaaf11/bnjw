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
        nodeP8 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static void delNode(nodeP8 *n) {
    n->deleted = true;
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