#include <iostream>
#include "show-pset3.h"
using namespace std;


struct nodeP17 {
    int value;
    nodeP17 *next;

    nodeP17(int v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP17 **head, int v) {
    cout << "Adding: " << v << endl;
    nodeP17 *newnode = new nodeP17(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP17 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


int getSize(nodeP17 *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


static int finder(nodeP17 *head, int nth) {
    int totalSize = getSize(head);
    
    if (nth > totalSize || nth <= 0) {
        throw runtime_error("Invalid value for n.");
    }

    totalSize--;

    while (head) {
        if (totalSize < nth) {
            break;
        }

        head = head->next;
        totalSize--;
    }

    return head->value;
}


static void printList(nodeP17 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
    cout << endl;
}


void showP17() {
    nodeP17 *first = NULL;

    insertNode(&first, 1);
    insertNode(&first, 5);
    insertNode(&first, 2);
    insertNode(&first, 3);
    insertNode(&first, 4);

    cout << "The list is: ";
    printList(first);

    cout << "nth: ";
    int n;
    cin >> n;

    cout << finder(first, n) << endl;
}