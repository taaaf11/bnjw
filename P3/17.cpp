#include <iostream>
#include <vector>
#include <unordered_set>
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

struct Queue {
    vector<int> v;
    int rear, totals;

    Queue(int totals) {
        rear = 0;
        v.assign(totals, -1);
        this->totals = totals;
    }

    int add(nodeP17 *curr) {
        int count = 0;
        nodeP17 *getSize = curr;
        while (getSize) {
            count++;
            getSize=getSize->next;
        }
        if (count < totals) {
            return -1;
        }
        
        for (int i = 0; i < totals; i++) {
            v[i] = curr->value;
            curr =curr->next;
        }
        return 0;
    }
};


int finder(nodeP17 *head, int nth) {
    Queue q(nth);
    nodeP17 *parent = NULL;
    while (head) {
        if (q.add(head) != 0) {
            break;
        }

        parent = head;
        head = head->next;
    }

    return parent->value;
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