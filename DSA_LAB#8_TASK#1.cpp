#include <iostream>
using namespace std;

class MyQueueArray {
private:
    int arr[100]; 
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    MyQueueArray() {
        frontIndex = 0;
        rearIndex = -1;
        capacity = 100;
    }

    void enqueue(int x) {
        if (rearIndex == capacity - 1) {
            cout << " Cannot insert " << x << endl;
            return;
        }
        rearIndex++;
        arr[rearIndex] = x;
        cout << x << " inserted into queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << " Queue is empty" << endl;
            return;
        }
        cout << arr[frontIndex] << " removed from queue" << endl;
        frontIndex++;
    }

    void showFront() {
        if (isEmpty()) cout << "Queue is empty" << endl;
        else cout << "Front element: " << arr[frontIndex] << endl;
    }

    bool isEmpty() {
        return frontIndex > rearIndex;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = frontIndex; i <= rearIndex; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MyQueueArray q;
    int choice, value;

    do {
        cout << "\n--- Array Queue Menu ---\n";
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
