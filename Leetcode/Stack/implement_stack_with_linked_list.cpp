#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;

    }
};
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if(isEmpty()) {
            cout << "Stack empty" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() {
        if(isEmpty()) {
            cout << "Stack empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while(!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack st;
    st.push(18);
    st.push(345);
    st.push(32);
    cout << "Top:" << " " << st.peek() << endl;
    cout << "Popped:" << " " << st.pop() << endl;
    cout << "Top:" << " " << st.peek() << endl;
    cout << "Popped:" << " " << st.pop() << endl;
    cout << "Top:" << " " << st.peek() << endl;
    cout << "Popped:" << " " << st.pop() << endl;
    cout << "Popped:" << " " << st.pop() << endl;


    return 0;
}