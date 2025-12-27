#include <iostream>
#include <utility>
#include <stack>
#include "show-pset1.h"
using namespace std;

struct nodeP4 {
    int value;
    nodeP4 *next;

    nodeP4(int v) {
        value = v;
        next = NULL;
    }
};


static int getSize(nodeP4 *head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    return size;
}

static pair<nodeP4 *, nodeP4 *> midsplit(nodeP4 *head, int size) {
    nodeP4 *current = head;
    nodeP4 *secondPart = NULL;
    for (int i = 1; i <= ((size - 1) / 2); i++) {
        // if (i == 0) {
        //     current = head;
        //     continue;
        // }
        // cout << "Adding " << current->value << endl;
        current = current->next;
    }
    secondPart = current->next;
    current->next = NULL;
    
    return {head, secondPart};
}


static void insertNode(nodeP4 **head, int v) {
    nodeP4 *newnode = new nodeP4(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP4 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}

static void reverse(nodeP4 *head) {
    nodeP4 *current = head;
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

static bool compareLists(nodeP4 *one, nodeP4 *two) {
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


static void printList(nodeP4 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

void showP4() {
    nodeP4 *head = NULL;
    int size = 5;

    insertNode(&head, 1);
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 3);
    insertNode(&head, 1);
    
    cout << "Original list: ";
    printList(head);
    cout << endl;

    pair<nodeP4 *, nodeP4 *> splitted = midsplit(head, size);
    nodeP4 *firstPart = splitted.first;
    nodeP4 *secondPart = splitted.second;

    nodeP4 *secondStart = NULL;

    if (size % 2 != 0) {
        nodeP4 *current = firstPart;
        while (current && current->next) {
            current = current->next;
        }

        secondStart = new nodeP4(current->value);
        secondStart->next = secondPart;
        secondPart = secondStart;
    }

    reverse(secondPart);

    // cout << endl;
    // cout << endl;
    // cout << endl;
    // printList(firstPart);
    // cout << endl;
    // printList(secondPart);
    // cout << endl;
    
    if (compareLists(firstPart, secondPart)) {
        cout << "Yes, given list is palindrome." << endl;
    }
    else {
        cout << "Not a palindrome." << endl;
    }
}