#include <iostream>
#include "show-pset1.h"
using namespace std;


struct nodeP6 {
    char value;
    nodeP6 *next;

    nodeP6(char v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP6 **head, char v) {
    nodeP6 *newnode = new nodeP6(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP6 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static nodeP6* findLoopStart(nodeP6* head)
{
    nodeP6* slow = head;
    nodeP6* fast = head;

    // Phase 1: Detect cycle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    // Phase 2: Find loop start
    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void showP6() {
    nodeP6 *head = NULL;

    insertNode(&head, 'A');
    insertNode(&head, 'B');
    insertNode(&head, 'C');
    insertNode(&head, 'D');
    insertNode(&head, 'E');
    
    //make C apear after E
    head->next->next->next->next->next = head->next->next;

    nodeP6* cycleStarts = findLoopStart(head);

    cout << "The list is: " << "A -> " << "B -> " << "C -> " << "D -> " << "E -> " << "C -> ..." << endl;

    if (cycleStarts) {
        cout << "The cycle is detected at " << cycleStarts->value << endl;
    }
    else {
        cout << "The cycle is not there." << endl;
    }
}