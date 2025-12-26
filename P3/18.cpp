#include <iostream>
#include <stack>
using namespace std;




struct node {
    char value;
    node *next;

    node(char v) {
        value = v;
        next = NULL;
    }
};


void insertNode(node **head, char v) {
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

void delNode(node *head, char data) {
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

void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}



int main() {
    node *first = NULL;

    insertNode(&first, 'a');
    insertNode(&first, 'b');
    insertNode(&first, 'c');
    insertNode(&first, 'd');

    delNode(first, 'c');

    printList(first);

    return 0;
}