#include <iostream>
#include <stack>
#include "show-pset3.h"
using namespace std;




struct nodeP19 {
    int value;
    nodeP19 *next;

    nodeP19(int v) {
        value = v;
        next = NULL;
    }
};


static void insertNode(nodeP19 **head, int v) {
    nodeP19 *newnode = new nodeP19(v);
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    else {
        nodeP19 *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}


static void reverse(nodeP19 *head) {
    nodeP19 *current = head;
    stack<int> s;
    while (current) {
        s.push(current->value);
        current = current->next;
    }
    current = head;
    while (!s.empty()) {
        current->value = s.top();
        s.pop();
        current = current->next;
    }
}


nodeP19* addTwoNums(nodeP19 *first, nodeP19 *second) {
    reverse(first);
    reverse(second);

    stack<int> resultStack;
    stack<int> expr1Stack;
    stack<int> expr2Stack;

    nodeP19 *curr = first;
    while (curr) {
        expr1Stack.push(curr->value);
        curr=curr->next;
    }
    curr = second;
    while (curr) {
        expr2Stack.push(curr->value);
        curr=curr->next;
    }

    int carry = 0, sum = 0;
    while (!expr1Stack.empty() || !expr2Stack.empty())
    {
        int expr1Num, expr2Num;
        if (expr1Stack.empty())
        {
            expr1Num = 0;
        }
        else
        {
            expr1Num = expr1Stack.top();
            expr1Stack.pop();
        }

        if (expr2Stack.empty())
        {
            expr2Num = 0;
        }
        else
        {
            expr2Num = expr2Stack.top();
            expr2Stack.pop();
        }

        sum = expr1Num + expr2Num;
        sum += carry;
        carry = 0;

        if (sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        resultStack.push(sum);
    }
    if (carry != 0)
    {
        resultStack.push(carry);
    }

    nodeP19 *result = NULL;
    stack<int> auxStack;
    
    while (!resultStack.empty())
    {
        // cout << resultStack.top();
        auxStack.push(resultStack.top());
        resultStack.pop();
    }

    while (!auxStack.empty()) {
        insertNode(&result, auxStack.top());
        auxStack.pop();
    }

    return result;
}

static void printList(nodeP19 *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}


void showP19() {
    nodeP19 *first = NULL;
    nodeP19 *second = NULL;

    insertNode(&first, 3);
    insertNode(&first, 1);
    insertNode(&first, 9);
    insertNode(&first, 9);

    insertNode(&second, 5);
    insertNode(&second, 9);
    insertNode(&second, 2);

    nodeP19 *result = addTwoNums(first, second);

    cout << "After adding 9913 and 295 (reversed): "<<endl;;
    printList(result);
}