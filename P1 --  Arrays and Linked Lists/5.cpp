#include <iostream>
using namespace std;


struct node {
    int value;
    node *next;

    node(int v) {
        value = v;
        next = NULL;
    }
};

void insertNode(node **head, int v) {
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

void createSorted(node *first, node *second, node **big) {
    node *parent = NULL;
    while (first) {
        while (second && second->value < first->value) {
            node *temp = second->next;

            second->next = first;
            parent->next = second;
            
            parent = first;
            first = second;
            second = temp;
        }
        parent = first;
        first = first->next;
    }
    // while (first && second) {
    //     if (first->value <= second->value) {
    //         insertNode(big, first->value);
    //         first = first->next;
    //     }
    //     else {
    //         insertNode(big, second->value);
    //         second = second->next;
    //     }
    // }

    // while (first) {
    //     insertNode(big, first->value);
    //     first = first->next;
    // }

    // while (second) {
    //     insertNode(big, second->value);
    //     second = second->next;
    // }
}

void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

int main() {
    node *first = NULL;
    node *second = NULL;
    node *big = NULL;

    
    insertNode(&first, 1);
    insertNode(&first, 5);
    insertNode(&first, 6);
    insertNode(&first, 7);

    insertNode(&second, 2);
    insertNode(&second, 3);
    insertNode(&second, 4);
    // insertNode(&second, 13);


    createSorted(first, second, &big);

    cout << "First list: ";
    printList(first);

    // cout << endl << "Second list: ";
    // printList(second);

    // cout << endl << "Merged list: ";
    // printList(big);

    return 0;
}