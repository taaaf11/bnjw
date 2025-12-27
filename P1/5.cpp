#include <iostream>
#include "show-pset1.h"
using namespace std;


struct nodeP5 {
    int value;
    nodeP5 *next;

    nodeP5(int v) {
        value = v;
        next = NULL;
    }
};

static void insertNode(nodeP5 **head, int v) {
    nodeP5 *newnode = new nodeP5(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP5 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}

static void createSorted(nodeP5 *first, nodeP5 *second) {
    nodeP5 *parent = NULL;

    while (first) {
        while (second && second->value < first->value) {
            nodeP5 *temp = second->next;

            second->next = first;
            parent->next = second;
            
            parent = first;
            first = second;
            second = temp;
        }
        parent = first;
        first = first->next;
    }
}

static void printList(nodeP5 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

void showP5() {
    nodeP5 *first = NULL;
    nodeP5 *second = NULL;

    insertNode(&first, 1);
    insertNode(&first, 5);
    insertNode(&first, 6);
    insertNode(&first, 7);

    insertNode(&second, 2);
    insertNode(&second, 3);
    insertNode(&second, 4);

    cout << "First list: ";
    printList(first);
    cout << endl << "Second list: ";
    printList(second);

    
    createSorted(first, second);

    cout << endl << "Sorted: ";
    printList(first);
    cout << endl;
}