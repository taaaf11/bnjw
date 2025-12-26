#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <initializer_list>
using namespace std;


struct TrainBogies {
    queue<int> q1;

    TrainBogies(initializer_list<int> l) {
        for (int i: l) {
            q1.push(i);
        }
    }

    int dequeue() {
        queue<int> q2;
        stack<int> s;

        if (q1.empty()) {
            cout << "Empty." << endl;
            exit(1);
        }

        int min = q1.front();
        q1.pop();
        q2.push(min);
        s.push(min);

        while (!q1.empty()) {
            int v = q1.front();
            q1.pop();

            q2.push(v);

            if (min > v) {
                min = v;
            }

            if (!s.empty()) {
                if (v < s.top()) {
                    s.push(v);
                }
            }
            else {
                s.push(v);
            }
        }
        
        int toRemove = s.top();
        
        while (!q2.empty()) {
            int v = q2.front();
            q2.pop();

            if (v == toRemove) {
                continue;
            }
            else {
                q1.push(v);
            }
        }

        return toRemove;
    }
};

int main() {
    TrainBogies t1{9, 5, 6, 1, 3};

    while (true) {
        cout << t1.dequeue() << endl;
    }

    return 0;
}
