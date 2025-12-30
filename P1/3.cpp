#include <iostream>
using namespace std;

struct nodeP3 {
	string name;
	int emergencyLevel;
	nodeP3* next;
	
	nodeP3(string n, int el)
	{
		name = n;
		emergencyLevel = el;
		next = nullptr;
	}
};

// nodeP3* head = nullptr;
// nodeP3* tail = nullptr;

void insertFunction(nodeP3* &head, nodeP3* &tail, string name, int emergencyLevel) // Faizan, 2
{
	nodeP3* newNode = new nodeP3(name, emergencyLevel);  //newNode = (Faizan, 3)
	cout << "Enqueueing: " << name << " with emergency level " << emergencyLevel << endl;
	if (head == nullptr) // checking head == NULL
	{
		head = tail = newNode; // head <- [ Faizan | 3 | next ] -> tail
		return;
	}
	
	// front insert
	if (emergencyLevel < head->emergencyLevel)  // 2 < 3
	{
		newNode->next = head; // newNode [next] = head ::: now it has head node address
		head = newNode;	// so now newNode becomes head node
	}
	
	// middle insert
	nodeP3* current = head;
	while(current->next != nullptr && current->next->emergencyLevel <= emergencyLevel) // head -> next != nullptr && 3 <= 4
 	{
		current = current->next; // head = head->next
	}
	
	newNode->next = current->next; // newNode-next = head->newNode
	current->next = newNode; // next -> newNode
	
	// end insert
	if(newNode->next == nullptr) // check newNode->next == NULL
	{
		tail = newNode;  // tail -> newNode
	}
	
}


void dequeue(nodeP3* &head, nodeP3* &tail) {
    if (head == NULL) {
        throw runtime_error("Queue is empty.");
    }

    if (head == tail) {
        tail = NULL;
    }

    cout << "Patient name: " << head->name << endl;
    if (head->emergencyLevel != -1) {
        cout << "Patient emergency level: " << head->emergencyLevel << endl;
    }
    else {
        cout << "Patient emergency level: Normal" << endl;
    }
    
    
    nodeP3 *temp = head;
    head = head->next;
    delete temp;
}

void showP3()
{
    nodeP3 *head = NULL;
    nodeP3 *tail = NULL;

    insertFunction(head, tail, "Normal 1", -1);
    insertFunction(head, tail, "Normal 2", -1);
    insertFunction(head, tail, "Normal 3", -1);
    insertFunction(head, tail, "Normal 4", -1);
    insertFunction(head, tail, "Normal 5", -1);

    insertFunction(head, tail, "Faizan", 2);
    insertFunction(head, tail, "altaaf", 3);
    
    while (true) {
        try {
            dequeue(head, tail);
        }
        catch (...) {
            cout << "Queue is empty." << endl;
            break;
        }
    }
}