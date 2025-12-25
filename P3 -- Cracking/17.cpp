#include <iostream>
#include <vector>
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

struct Queue {
    vector<int> v;
    int rear, totals;

    Queue(int totals) {
        rear = 0;
        v.assign(totals, -1);
        this->totals = totals;
    }

    int add(node *curr) {
        int count = 0;
        node *getSize = curr;
        while (getSize) {
            count++;
            getSize=getSize->next;
        }
        if (count < totals) {
            return -1;
        }
        
        for (int i = 0; i < totals; i++) {
            v[i] = curr->value;
            curr =curr->next;
        }
        return 0;
    }

    // void add(int value) {
    //     rear = rear % (totals);
    //     v[rear] = value;
    //     rear += 1;
    //     if (rear == totals) {
    //         rear--;
    //     }
    // }
};


struct ArrayView {
    int start;
    int end;
    vector<int>& array;

    ArrayView(vector<int>& v, int s, int e): start(s), end(e), array(v) {}
};



int finder(node *head, int nth) {
    Queue q(nth);
    node *parent = NULL;
    while (head) {
        if (q.add(head) != 0) {
            break;
        }

        parent = head;
        head = head->next;
    }

    return parent->value;
    // return q.v[0];
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


void removeDuplicates(node *head) {
    unordered_set<char> visited;
    node *parent = NULL;
    while (head) {
        if (visited.find(head->value) != visited.end()) {
            node *temp = head->next;
            parent->next = head->next;
            delete head;
            head = temp;
            continue;
        }

        visited.insert(head->value);
        parent = head;
        head = head->next;
    }
}

void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}



int main() {
    node *first = NULL;

    insertNode(&first, 1);
    insertNode(&first, 5);
    insertNode(&first, 2);
    insertNode(&first, 3);
    insertNode(&first, 4);

    cout << finder(first,1) << endl;;

    printList(first);

    return 0;
}