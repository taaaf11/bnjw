#include <iostream>
#include <stack>
using namespace std;


char getOpening(char closing) {
    if (closing == ')') {
        return '(';
    }
    else if (closing == ']') {
        return '[';
    }
    else if (closing == '}') {
        return '{';
    }
    else if (closing == '>') {
        return '<';
    }
    else {
        return 0;
    }
}

char getClosing(char opening) {
    if (opening == '(') {
        return ')';
    }
    else if (opening == '[') {
        return ']';
    }
    else if (opening == '{') {
        return '}';
    }
    else if (opening == '<') {
        return '>';
    }
    else {
        return 0;
    }
}

bool isBracket(char c) {
    return (getOpening(c) != 0) || (getClosing(c) != 0);
}

void paransChecker(string expr) {
    stack<char> s;

    for (char c: expr) {
        if (!isBracket(c)) { continue; }

        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            if (s.empty()) {
                cout << "Ending  bracket without matching opener." << endl;
                exit(1);
            }
            
            if (
                c != getClosing(s.top())
            )
            {
                cout << "Expected " << getClosing(s.top()) << ", found " << c << endl;
            }
            s.pop();
        }
    }
}


int main() {
    string expr = "a{b(c]d}";

    paransChecker(expr);
    return 0;
}