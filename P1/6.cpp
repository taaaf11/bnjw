#include <iostream>
#include "show-pset1.h"
using namespace std;


struct nodeP6 {
    char value;
    nodeP6 *next;

    nodeP6(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP6 **head, char v) {
    nodeP6 *newnode = new nodeP6(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP6 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static bool algorithm(nodeP6 *l) {
    if (l == NULL) {
        return false;
    }

    nodeP6 *tortoise = l;
    nodeP6 *hare = l;

    while (hare && hare->next) {
        if (hare == tortoise) {
            return true;
        }
        // if (hare->next == tortoise || hare->next->next == tortoise) {
        //     return true;
        // }
        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    return false;
}

void showP6() {
    nodeP6 *head = NULL;

    insertNode(&head, 'A');
    insertNode(&head, 'B');
    insertNode(&head, 'C');
    insertNode(&head, 'D');
    insertNode(&head, 'E');
    
    //make C apear after E
    head->next->next->next->next->next = head->next->next;

    bool hasCycles = algorithm(head);

    if (hasCycles) {
        cout << "The cycle is detected." << endl;
    }
    else {
        cout << "The cycle is not there." << endl;
    }
}