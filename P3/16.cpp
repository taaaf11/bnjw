#include <iostream>
#include <unordered_set>
using namespace std;


#include "show-pset3.h"


struct nodeP16 {
    char value;
    nodeP16 *next;

    nodeP16(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP16 **head, char v) {
    cout << "Adding node: " << v << endl;
    nodeP16 *newnode = new nodeP16(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP16 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}

static void delNode(nodeP16 *head, char data) {
    nodeP16 *parent = NULL;
    while (head) {
        if (head->value == data) {
            break;
        }
        parent = head;
        head = head->next;
    }

    // noed was not there
    if (head == NULL) {
        return;
    }

    parent->next = head->next;
    delete head;
}


static void removeDuplicates(nodeP16 *head) {
    unordered_set<char> visited;
    nodeP16 *parent = NULL;
    while (head) {
        if (visited.find(head->value) != visited.end()) {
            nodeP16 *temp = head->next;
            parent->next = head->next;
            delete head;
            head = temp;
            continue;
        }

        visited.insert(head->value);
        parent = head;
        head = head->next;
    }
}

static void printList(nodeP16 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}


void showP16() {
    nodeP16 *first = NULL;

    insertNode(&first, 'a');
    insertNode(&first, 'b');
    insertNode(&first, 'c');
    insertNode(&first, 'd');
    insertNode(&first, 'b');

    cout << "Before: ";
    printList(first);

    cout << endl;

    removeDuplicates(first);

    cout << "After: ";
    printList(first);
}


// int main() {
//     nodeP16 *first = NULL;

//     insertNode(&first, 'a');
//     insertNode(&first, 'b');
//     insertNode(&first, 'c');
//     insertNode(&first, 'd');
//     insertNode(&first, 'b');

//     removeDuplicates(first);

//     printList(first);

//     return 0;
// }