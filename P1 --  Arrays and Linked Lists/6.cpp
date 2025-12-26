#include <iostream>
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


bool algorithm(node *l) {
    if (l == NULL) {
        return false;
    }

    node *tortoise = l;
    node *hare = l;

    while (hare && hare->next) {
        if (hare == tortoise) {
            return true;
        }
        // if (hare->next == tortoise || hare->next->next == tortoise) {
        //     return true;
        // }
        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    return false;
}

int main() {
    node *head = NULL;

    insertNode(&head, 'A');
    insertNode(&head, 'B');
    insertNode(&head, 'C');
    insertNode(&head, 'D');
    insertNode(&head, 'E');
    
    //make C apear after E
    head->next->next->next->next->next = head->next->next;

    bool hasCycles = algorithm(head);

    if (hasCycles) {
        cout << "The cycle is detected." << endl;
    }
    else {
        cout << "The cycle is not there." << endl;
    }
}