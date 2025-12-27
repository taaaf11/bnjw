#include <iostream>
#include "show-pset1.h"
using namespace std;

struct nodeP9 {
    int value;
    nodeP9 *next;

    nodeP9(int v) {
        value = v;
        next = NULL;
    }
};


struct Deque
{
    nodeP9 *head;
    nodeP9 *tail;

    Deque() {
        head = NULL;
        tail = NULL;
    }

    void insertFront(int value) {
        cout << "Inserting " << value << " at front" << endl;
        nodeP9 *newnode =  new nodeP9(value);
        
        if (!head) {
            head = tail = newnode;
            return;
        }

        else {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertRear(int value) {
        cout << "Inserting " << value << " at rear" << endl;
        nodeP9 *newnode =  new nodeP9(value);
        
        if (!head) {
            head = tail = newnode;
            return;
        }

        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    int removeFront() {
        if (!head) {
            throw runtime_error("Queue is empty.");
        }

        if (head == tail) {
            int value = head->value;
            delete head;
            head = tail = NULL;
            cout << "Deleting " << value << " at front." << endl;
            return value;
        }

        nodeP9 *temp = head;
        int value = head->value;
        head = head->next;
        delete temp;
        cout << "Deleting " << value << " at front." << endl;
        return value;
    }

    int removeRear() {
        if (!head) {
            throw runtime_error("Queue is empty.");
        }

        
        if (head == tail) {
            int value = head->value;
            delete head;
            head = tail = NULL;
            cout << "Deleting " << value << " at rear" << endl;
            return value;
        }

        nodeP9 *temp = head;
        while (temp && temp->next  != tail) {
            temp = temp->next;
        }
        int value = tail->value;
        cout << "Deleting " << value << " at rear" << endl;

        delete tail;
        temp = temp;
    }
};

void showP9()
{
    Deque d;

    d.insertFront(1);
    d.insertFront(4);
    d.insertRear(7);
    d.insertRear(5);
    
    while (true) {
        try {
            d.removeFront();
        }
        catch (...) {
            break;
        }
        // cout << d.removeFront() << endl;
    }
}