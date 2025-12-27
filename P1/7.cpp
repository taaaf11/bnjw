#include <iostream>
#include <unordered_set>
#include "show-pset1.h"
using namespace std;

struct nodeP7 {
    int value;
    nodeP7 *next;

    nodeP7(int v) {
        value = v;
        next = NULL;
    }
};

static void insertNode(nodeP7 **head, int v) {
    nodeP7 *newnode = new nodeP7(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP7 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static void removeConsecutives(nodeP7 *head, int k) {
    int i = 0;
    nodeP7 *parent = NULL;
    nodeP7 *current = head;
    nodeP7 *seqStart = NULL;

    while (current) {
        if (current->value == 0) {
            i += 1;
            if (!seqStart)
                seqStart = parent;
                // seqStart = current;

            parent  = current;
            current = current->next;
            continue;
        }

        if (i >= k) {
            i = 0;
            seqStart->next = current;
            seqStart = NULL;
            parent = current;
            if (current)
                current = current->next;
        }
        
        // if (i == k) {
        //     i = 0;

        //     parent->
        // }
        parent = current;
        if (current)
            current = current->next;
    }
}


static void printList(nodeP7 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

void showP7() {
    nodeP7 *head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 1);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 1);

    cout << "Before: ";
    printList(head);

    removeConsecutives(head, 5);

    cout << endl << "After: ";
    printList(head);
}