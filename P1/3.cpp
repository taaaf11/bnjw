#include <iostream>
#include "show-pset1.h"
using namespace std;

struct node {
    int patient;
    int priority;
    node *next;

    node(int pat, int pri = -1) {
        patient = pat;
        priority = pri;
        next = NULL;
    }    
};

node *head = NULL;

static void insertNormal(int patient) {
    node *newnode = new node(patient);

    if (!head) {
        head = newnode;
        return;
    }
    
    node *current = head;

    while (current->next) {
        current = current->next;
    }

    current->next = newnode;
}

static void insertPriority(int patient, int priority) {
    node *newnode = new node(patient, priority);
    if (!head) {
        head = newnode;
        return;
    }
    if (head->priority < priority) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node *current = head;

    while (current && current->next && current->next->priority >= priority) {
        // if (current->priority < priority) {
        //     break;
        // }
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;

    // node *newnode = new node(patient, priority);
}


static int dequeue() {
    if (head == NULL) {
        throw runtime_error("No patients left in queue.");
    }

    node *temp = head;

    int value = temp->patient;
    head = head->next;

    delete temp;

    return value;
}

void showP3() {
    insertNormal(1);
    insertNormal(2);
    insertNormal(3);
    insertPriority(10, 1);
    insertPriority(20, 1);
    insertPriority(30, 1);
    insertPriority(100, 2);
    insertPriority(200, 2);
    insertPriority(300, 2);

    while (true) {
        try {
            cout << dequeue() << endl;
        }
        catch (...) {
            cout << "Queue is empty." << endl;
            break;
        }
    }
}