#include <iostream>
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


struct Deque
{
    node *head;
    node *tail;

    Deque() {
        head = NULL;
        tail = NULL;
    }

    void insertFront(int value) {
        node *newnode =  new node(value);
        
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
        node *newnode =  new node(value);
        
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
            return value;
        }

        node *temp = head;
        int value = head->value;
        head = head->next;
        delete temp;
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
            return value;
        }

        node *temp = head;
        while (temp && temp->next  != tail) {
            temp = temp->next;
        }
        int value = tail->value;

        delete tail;
        temp = temp;
    }
};

void showP9()
{
    Deque d;

    d.insertFront(1);
    d.insertFront(2);
    d.insertFront(3);
    d.insertFront(4);
    d.insertRear(7);
    d.insertRear(6);
    d.insertRear(5);
    
    while (true) {
        cout << d.removeFront() << endl;
    }
}