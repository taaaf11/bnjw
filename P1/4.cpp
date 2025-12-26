#include <iostream>
#include <utility>
#include <stack>
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


static int getSize(node *head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    return size;
}

static pair<node *, node *> midsplit(node *head, int size) {
    node *current = head;
    node *secondPart = NULL;
    for (int i = 1; i <= ((size - 1) / 2); i++) {
        // if (i == 0) {
        //     current = head;
        //     continue;
        // }
        cout << "Adding " << current->value << endl;
        current = current->next;
    }
    secondPart = current->next;
    current->next = NULL;
    
    return {head, secondPart};
}


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

static void reverse(node *head) {
    node *current = head;
    stack<int> s;
    while (current) {
        s.push(current->value);
        current = current->next;
    }
    current = head;
    while (!s.empty()) {
        current->value = s.top();
        s.pop();
        current = current->next;
    }
}

static bool compareLists(node *one, node *two) {
    while (one && two) {
        if (one->value != two->value) {
            return false;
        }
        one = one->next;
        two = two->next;
    }

    if (one || two) {
        return false;
    }

    return true;
}


static void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

void showP4() {
    node *head = NULL;
    int size = 5;

    insertNode(&head, 1);
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 3);
    insertNode(&head, 1);
    
    printList(head);

    pair<node *, node *> splitted = midsplit(head, size);
    node *firstPart = splitted.first;
    node *secondPart = splitted.second;

    node *secondStart = NULL;

    if (size % 2 != 0) {
        node *current = firstPart;
        while (current && current->next) {
            current = current->next;
        }

        secondStart = new node(current->value);
        secondStart->next = secondPart;
        secondPart = secondStart;
    }

    reverse(secondPart);

    cout << endl;
    cout << endl;
    cout << endl;
    printList(firstPart);
    cout << endl;
    printList(secondPart);
    cout << endl;
    cout << compareLists(firstPart, secondPart) << endl;
}