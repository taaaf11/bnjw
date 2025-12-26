#include <iostream>
#include <unordered_set>
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


void removeConsecutives(node *head, int k) {
    int i = 0;
    node *parent = NULL;
    node *current = head;
    node *seqStart = NULL;

    while (current) {
        if (current->value == 0) {
            i += 1;
            if (!seqStart)
                seqStart = parent;
                // seqStart = current;

            parent  = current;
            current = current->next;
            continue;
        }

        if (i >= k) {
            i = 0;
            seqStart->next = current;
            seqStart = NULL;
            parent = current;
            if (current)
                current = current->next;
        }
        
        // if (i == k) {
        //     i = 0;

        //     parent->
        // }
        parent = current;
        if (current)
            current = current->next;
    }
}


void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}

int main() {
    node *head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 1);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 0);
    insertNode(&head, 0);
    // insertNode(&head, 0);
    insertNode(&head, 1);

    removeConsecutives(head, 5);

    printList(head);


    // head->next->next->next->next->next = head->next->next;

    // node *cycleDetect = detectCycle(head);

    // if (cycleDetect) {
    //     cout << "Cycle detected at: " << cycleDetect->value << endl;
    // }
    // else {
    //     cout << "No cycles." << endl;
    // }

    return 0;
}