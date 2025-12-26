#include <iostream>
#include "show-pset1.h"
using namespace std;


struct node {
    int value;
    node *next;

    node(int v) {
        value = v;
        next = NULL;
    }
};

static void insertNode(node **head, int v) {
    node *newnode = new node(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        node *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}

static void createSorted(node *first, node *second) {
    node *parent = NULL;

    while (first) {
        while (second && second->value < first->value) {
            node *temp = second->next;

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

static void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

void showP5() {
    node *first = NULL;
    node *second = NULL;

    insertNode(&first, 1);
    insertNode(&first, 5);
    insertNode(&first, 6);
    insertNode(&first, 7);

    insertNode(&second, 2);
    insertNode(&second, 3);
    insertNode(&second, 4);

    createSorted(first, second);

    cout << "First list: ";
    printList(first);
}