#include <iostream>
using namespace std;

struct nodeP5 {
	int data;
	nodeP5* next;
	
	nodeP5(int d) : data(d), next(nullptr) {
	}
};

// nodeP5* head = NULL;
// nodeP5* tail = NULL;

static nodeP5* mergeSorted(nodeP5* a, nodeP5* b)
{
    // EDGE CASES
    if (!a) return b;
    if (!b) return a;

    nodeP5* head = nullptr;
    nodeP5* tail = nullptr;

    // Initialize head
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    // Merge by pointer relinking
    while (a && b)
    {
        if (a->data <= b->data)
        {
            tail->next = a;   // relink
            a = a->next;
        }
        else
        {
            tail->next = b;   // relink
            b = b->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = (a) ? a : b;

    return head;
}


static void insertEnd(nodeP5*& head, int price)
{
    nodeP5* newNode = new nodeP5(price);
    if (!head)
    {
        head = newNode;
        return;
    }

    nodeP5* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

static void printList(nodeP5* head)
{
    while (head)
    {
        cout << head->data << " ? ";
        head = head->next;
    }
    cout << "NULL\n";
}


static void printFun(nodeP5* &head)
{
	while(head)
	{
		cout << head->next << endl;
		head = head->next;
	}
}

void showP5()
{
    nodeP5* A = nullptr;
    nodeP5* B = nullptr;

    insertEnd(A, 1);
    insertEnd(A, 5);
    insertEnd(A, 7);

    insertEnd(B, 2);
    insertEnd(B, 3);
    insertEnd(B, 6);

    cout << "Company A: ";
    printList(A);

    cout << "Company B: ";
    printList(B);

    nodeP5* merged = mergeSorted(A, B);

    cout << "Merged Prices: ";
    printList(merged);
}