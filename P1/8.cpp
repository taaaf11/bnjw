#include <iostream>
#include <stack>
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

// static void delNode(nodeP8 *head, char data) {
//     nodeP8 *parent = NULL;
//     while (head) {
//         if (head->value == data) {
//             break;
//         }
//         parent = head;
//         head = head->next;
//     }

//     // noed was not there
//     if (head == NULL) {
//         return;
//     }

//     parent->next = head->next;
//     delete head;
// }

static void delNode(nodeP8 *n) {
    if (n->next) {
        nodeP8 *parent = n;
        nodeP8 *temp = n->next;
        while (temp) {
            if (temp->next  == NULL) {
                n->next = NULL;
            }
            n->value = temp->value;
            n = temp;
            temp = temp->next;
            parent = parent->next;
        }
    }
    else { // the noed is tail
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

    delNode(first);

    printList(first);
}