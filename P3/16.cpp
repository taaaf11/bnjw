#include <iostream>
#include <unordered_set>
using namespace std;


#include "show-pset3.h"


struct node {
    char value;
    node *next;

    node(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(node **head, char v) {
    cout << "Adding node: " << v << endl;
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

static void delNode(node *head, char data) {
    node *parent = NULL;
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


static void removeDuplicates(node *head) {
    unordered_set<char> visited;
    node *parent = NULL;
    while (head) {
        if (visited.find(head->value) != visited.end()) {
            node *temp = head->next;
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

static void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}


void showP16() {
    node *first = NULL;

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
//     node *first = NULL;

//     insertNode(&first, 'a');
//     insertNode(&first, 'b');
//     insertNode(&first, 'c');
//     insertNode(&first, 'd');
//     insertNode(&first, 'b');

//     removeDuplicates(first);

//     printList(first);

//     return 0;
// }