#include <iostream>
#include "show-pset1.h"
using namespace std;


struct nodeP10 {
    int data;
    nodeP10* next;

    nodeP10(int d) : data(d), next(nullptr) {}
};


void insertFun(nodeP10*& head, int d)
{
    nodeP10* newNode = new nodeP10(d);

    if (!head)
    {
        head = newNode;
        return;
    }

    nodeP10* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void printFun(nodeP10* head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

bool isSorted(nodeP10* head)
{
    while (head && head->next)
    {
        if (head->data > head->next->data)
            return false;

        head = head->next;
    }
    return true;
}


nodeP10* findMid(nodeP10* head)
{
    nodeP10* slow = head;
    nodeP10* fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


nodeP10* merge(nodeP10* a, nodeP10* b)
{
    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data)
    {
        a->next = merge(a->next, b);
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        return b;
    }
}


nodeP10* mergeSort(nodeP10* head)
{
    if (!head || !head->next)
        return head;

    // Optimization
    if (isSorted(head))
        return head;

    nodeP10* mid = findMid(head);
    nodeP10* right = mid->next;
    mid->next = nullptr;

    nodeP10* left = mergeSort(head);
    nodeP10* sortedRight = mergeSort(right);

    return merge(left, sortedRight);
}

void showP10()
{
    nodeP10* head = nullptr;

    insertFun(head, 3);
    insertFun(head, 2);
    insertFun(head, 1);
    insertFun(head, 4);
    insertFun(head, 5);

    cout << "Original List:\n";
    printFun(head);

    head = mergeSort(head);

    cout << "\nSorted List:\n";
    printFun(head);
}