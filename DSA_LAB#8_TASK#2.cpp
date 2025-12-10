#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class MyQueueLinked {
private:
    Node* front;
    Node* rear;

public:
    MyQueueLinked() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (rear == nullptr) front = rear = newNode;
        else { rear->next = newNode; rear = newNode; }
        cout << x << " inserted into queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << " Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " removed from queue" << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void showFront() {
        if (isEmpty()) cout << "Queue is empty" << endl;
        else cout << "Front element: " << front->data << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    MyQueueLinked q;
    int choice, value;

    do {
        cout << "\n--- Linked List Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Show Front\n4. Display Queue\n5. Check Empty\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.showFront();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty()) cout << "Queue is empty." << endl;
            else cout << "Queue is not empty." << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
