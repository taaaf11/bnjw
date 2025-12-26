#include <iostream>
#include <vector>
#include <unordered_set>
#include "show-pset3.h"
using namespace std;


struct node {
    int value;
    node *next;

    node(int v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(node **head, int v) {
    cout << "Adding: " << v << endl;
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

struct Queue {
    vector<int> v;
    int rear, totals;

    Queue(int totals) {
        rear = 0;
        v.assign(totals, -1);
        this->totals = totals;
    }

    int add(node *curr) {
        int count = 0;
        node *getSize = curr;
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


int finder(node *head, int nth) {
    Queue q(nth);
    node *parent = NULL;
    while (head) {
        if (q.add(head) != 0) {
            break;
        }

        parent = head;
        head = head->next;
    }

    return parent->value;
}


static void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
    cout << endl;
}


void showP17() {
    node *first = NULL;

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