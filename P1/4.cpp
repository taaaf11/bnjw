#include <iostream>
using namespace std;

struct nodeP4
{
    int data;
    nodeP4* next;

    nodeP4(int d)
    {
        data = d;
        next = nullptr;
    }
};

nodeP4* reverse(nodeP4* head)
{
    nodeP4* prev = nullptr;
    nodeP4* curr = head;
    nodeP4* next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;   // save -> next
        curr->next = prev;   // reverse -> link
        prev = curr;         // move -> prev
        curr = next;         // move -> curr
    }
    return prev;
}

bool isPalindrome(nodeP4* head)
{
    if (!head || !head->next)
        return true;

    nodeP4* slow = head;
    nodeP4* fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    nodeP4* secondHalf = reverse(slow->next);
    nodeP4* firstHalf = head;

    nodeP4* temp = secondHalf;
    bool result = true;

    while (temp)
    {
        if (firstHalf->data != temp->data)
        {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    slow->next = reverse(secondHalf);

    return result;
}

void insertEnd(nodeP4*& head, int value)
{
    nodeP4* newNode = new nodeP4(value);
    if (!head)
    {
        head = newNode;
        return;
    }

    nodeP4* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void printList(nodeP4* head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void showP4()
{
    nodeP4* head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 7);
    insertEnd(head, 3);
    insertEnd(head, 1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "Palindrome List\n";
    else
        cout << "Not a Palindrome\n";

    cout << "List after check (restored): ";
    printList(head);
}