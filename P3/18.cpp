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

// static void delNode(nodeP18 *head, char data) {
//     nodeP18 *parent = NULL;
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

static void delNode(nodeP18 *no) {
    no->deleted = true;
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
    
    delNode(first);

    cout << endl << "After deleting c: ";
    printList(first);
}