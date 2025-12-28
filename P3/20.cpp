#include <iostream>
#include <unordered_set>
#include "show-pset3.h"
using namespace std;

struct nodeP20 {
    char value;
    nodeP20 *next;

    nodeP20(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP20 **head, char v) {
    nodeP20 *newnode = new nodeP20(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP20 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


nodeP20* detectCycle(nodeP20 *head) {
    unordered_set<nodeP20 *> visited;

    while (head) {
        if (visited.find(head) != visited.end()) {
            return head;
        }

        visited.insert(head);
        head = head->next;
    }

    return NULL;
}

void showP20() {
    nodeP20 *head = NULL;

    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'd');
    insertNode(&head, 'e');

    cout << "The list is: " << "A -> " << "B -> " << "C -> " << "D -> " << "E -> " << "C -> ..." << endl;

    head->next->next->next->next->next = head->next->next;

    nodeP20 *cycleDetect = detectCycle(head);

    if (cycleDetect) {
        cout << "Cycle detected at: " << cycleDetect->value << endl;
    }
    else {
        cout << "No cycles." << endl;
    }
}