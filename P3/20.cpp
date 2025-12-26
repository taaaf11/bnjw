#include <iostream>
#include <unordered_set>
#include "show-pset3.h"
using namespace std;

struct node {
    char value;
    node *next;

    node(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(node **head, char v) {
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


node* detectCycle(node *head) {
    unordered_set<char> visited;

    while (head) {
        if (visited.find(head->value) != visited.end()) {
            return head;
        }

        visited.insert(head->value);
        head = head->next;
    }

    return NULL;
}

void showP20() {
    node *head = NULL;

    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'd');
    insertNode(&head, 'e');

    head->next->next->next->next->next = head->next->next;

    node *cycleDetect = detectCycle(head);

    if (cycleDetect) {
        cout << "Cycle detected at: " << cycleDetect->value << endl;
    }
    else {
        cout << "No cycles." << endl;
    }
}