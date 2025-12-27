#include <iostream>
#include "show-pset1.h"
using namespace std;

struct nodeP3 {
    int patient;
    int priority;
    nodeP3 *next;

    nodeP3(int pat, int pri = -1) {
        patient = pat;
        priority = pri;
        next = NULL;
    }    
};

nodeP3 *head = NULL;

static void insertNormal(int patient) {
    cout << "Inserting normal: " << patient << endl;
    nodeP3 *newnode = new nodeP3(patient);

    if (!head) {
        head = newnode;
        return;
    }
    
    nodeP3 *current = head;

    while (current->next) {
        current = current->next;
    }

    current->next = newnode;
}

static void insertPriority(int patient, int priority) {
    cout << "Inserting " << patient << " with priority " << priority << endl;
    nodeP3 *newnode = new nodeP3(patient, priority);
    if (!head) {
        head = newnode;
        return;
    }
    if (head->priority < priority) {
        newnode->next = head;
        head = newnode;
        return;
    }

    nodeP3 *current = head;

    while (current && current->next && current->next->priority >= priority) {
        // if (current->priority < priority) {
        //     break;
        // }
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;

    // nodeP3 *newnode = new nodeP3(patient, priority);
}


static int dequeue() {
    if (head == NULL) {
        throw runtime_error("No patients left in queue.");
    }

    nodeP3 *temp = head;

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

    cout << "Dequeueing" << endl;
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