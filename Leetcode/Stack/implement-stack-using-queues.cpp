#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    int top() {
        return q.front();
    }
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    cout << "Top: " << st.top() << endl; // Should print 20
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // Should print 10

    return 0;
}