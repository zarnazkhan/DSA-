#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
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
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack"<<endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty! Cannot pop"<<endl;
            return;
        }
        cout << top->data << " popped from stack" << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty"<<endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};
int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. View top element\n";
        cout << "4. Check if empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty"<<endl;
            else
                cout << "Stack is not empty"<<endl;
            break;

        case 5:
            cout << "Exiting program..."<<endl;
            return 0;

        default:
            cout << "Invalid choice! Try again"<<endl;
        }
    }
}
