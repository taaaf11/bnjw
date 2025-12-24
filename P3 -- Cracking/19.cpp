#include <iostream>
#include <stack>
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


void reverse(node *head) {
    node *current = head;
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


node* addTwoNums(node *first, node *second) {
    reverse(first);
    reverse(second);

    stack<int> resultStack;
    stack<int> expr1Stack;
    stack<int> expr2Stack;

    node *curr = first;
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

    node *result = NULL;
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

void printList(node *head) {
    while (head) {
        cout << head->value << " -> ";
        head=head->next;
    }
}


int main() {
    node *first = NULL;
    node *second = NULL;

    insertNode(&first, 3);
    insertNode(&first, 1);
    insertNode(&first, 9);
    insertNode(&first, 9);

    insertNode(&second, 5);
    insertNode(&second, 9);
    insertNode(&second, 2);

    node *result = addTwoNums(first, second);
    
    printList(result);

    return 0;
}