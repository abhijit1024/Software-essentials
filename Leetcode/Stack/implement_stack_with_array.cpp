#include<iostream>
using namespace std;

class stack {
private:
    int top;
    int st[10];

public:
    stack() {
        top = -1;
    }

    void push(int x) {
        if(top >= 9) {
            cout << "Stack overflow" << endl;
        }
        top = top + 1;
        st[top] = x;
    }
    int pop() {
        if(top == -1) {
            cout << "Stack empty" << endl;
            return -1;
        }
        int val = st[top];
        top = top - 1;
        return val;
    }
    int peek() {
        if(top == -1) {
            cout << "Stack empty" << endl;
            return -1;
        }
        return st[top];
    }
    bool isempty() {
        return (top == -1);
    }
};
int main() {
    stack st ;
    st.push(10);
    st.push(8);
    st.push(4);
    cout << "Top: " << st.peek() << endl;
    st.pop();
    st.pop();
    cout << "Top: " << st.peek() << endl;
    st.push(1);
    cout << "Top: " << st.peek() << endl;
    return 0;
}