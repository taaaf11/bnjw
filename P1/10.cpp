#include <iostream>
#include "show-pset1.h"
using namespace std;


class nodeP10 {
  public:
    int value;
    nodeP10 *next;

    nodeP10(int x) {
        value = x;
        next = NULL;
    }
};



static void insertNode(nodeP10 **head, char v) {
    nodeP10 *newnode = new nodeP10(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP10 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}



static void printList(nodeP10 *head) {
    nodeP10 *curr = head;
    while (curr) {
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

static nodeP10 *split(nodeP10 *head) {
    nodeP10 *fast = head;
    nodeP10 *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast) {
            slow = slow->next;
        }
    }

    nodeP10 *temp = slow->next;
    slow->next = NULL;
    return temp;
}


static nodeP10 *merge(nodeP10 *first, nodeP10 *second) {
    if (!first) {
        return second;
    }

    if (!second) {
        return first;
    }

    if (first->value <= second->value) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}


static int getSize(nodeP10 *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


// totalSize is not modified, it is just there for
// checking if sorting is done halfway.
static nodeP10 *mergeSort(nodeP10 *head, int totalSize) {
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (head == NULL || head->next == NULL)
        return head;
    
    nodeP10 *second = split(head);
    
    head = mergeSort(head, totalSize);
    second = mergeSort(second, totalSize);

    if (getSize(head) == totalSize / 2 || getSize(second) == totalSize / 2) {
        cout << "Halfway sorted." << endl;

        // This part will connect the two parts.
        nodeP10 *f = head;
        while (f) {
            if (f->next == NULL) {
                f->next = second;
                break;
            }
            f = f->next;
        }
        return head;
    }
    
    return merge(head, second);
}


void showP10() {
    nodeP10 *first = NULL;

    insertNode(&first, 9);
    insertNode(&first, 8);
    insertNode(&first, 5);
    insertNode(&first, 2);

    first = mergeSort(first, 4);

    printList(first);
}