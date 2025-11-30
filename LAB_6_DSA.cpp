#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No elements to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }
};

int main() {
    Stack st(5);

    int choice, value;

    do {
        cout << "\n Stack Menu \n";
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
            st.push(value);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            st.peek();
            break;

        case 4:
            if (st.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is NOT empty.\n";
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}