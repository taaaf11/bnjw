#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <initializer_list>
using namespace std;


// struct MyQueue {
//     vector<int> v;
//     int front, rear, totalSize;
//     // int totalSize;

//     MyQueue() {
//         front = rear = -1;
//         v.resize(100);
//     }

//     MyQueue(int totalSize) {
//         front = rear = -1;
//         this->totalSize = totalSize;
//         v.resize(totalSize);
//     }

//     MyQueue(initializer_list<int> l) {
//         front = 0;
//         v.assign(l);
//         totalSize = l.size();
//     }

//     void enqueue(int value) {
//         rear++;
//         v[rear] = value;
//         if (front == -1) {
//             front = 0;
//         }
//         totalSize++;
//     }

//     int dequeue() {
//         if (front == totalSize) {
//             cout << "Queue empty" << endl;
//             exit(1);
//         }
//         int elem = v[front];
//         front++;
//         return elem;
//     }

//     bool empty() {
//         return (front == totalSize);
//     }
// };


// struct TrainBogies {
//     MyQueue q1;
    
//     TrainBogies(initializer_list<int> l) {
//         for (int i: l) {
//             q1.enqueue(i);
//         }
//         // q1 = MyQueue(l);
//     }

//     void dequeue() {
//         MyQueue q2(q1.totalSize);
//         stack<int> s;

//         int &v = q1.dequeue();
//         q2.enqueue(v);
//         if (!s.empty()) {
//             if (v < s.top()) {
//                 s.push(v);
//             }
//         }
//         else {
//             s.push(v);
//         }
//     }
// };

struct TrainBogies2 {
    queue<int> q1;

    TrainBogies2(initializer_list<int> l) {
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
    TrainBogies2 t1{9, 5, 6, 1, 3};

    while (true) {
        cout << t1.dequeue() << endl;
    }

    return 0;
}
