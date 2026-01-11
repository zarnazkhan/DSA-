#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    int table[SIZE];
    list<int> chain[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;  
    }

    // Primary hash function
    int hash1(int key) {
        return key % SIZE;
    }

    // Secondary hash function (for double hashing)
    int hash2(int key) {
        return 7 - (key % 7);
    }

    //  INSERT 

    void insert(int key, int method) {
        int index = hash1(key);

        if (method == 1) { // Chaining
            chain[index].push_back(key);
            cout << "Inserted using chaining\n";
            return;
        }

        for (int i = 0; i < SIZE; i++) {
            int newIndex;

            if (method == 2)            // Linear Probing
                newIndex = (index + i) % SIZE;
            else if (method == 3)       // Quadratic Probing
                newIndex = (index + i * i) % SIZE;
            else if (method == 4)       // Double Hashing
                newIndex = (index + i * hash2(key)) % SIZE;
            else
                return;

            if (table[newIndex] == -1 || table[newIndex] == -2) {
                table[newIndex] = key;
                cout << "Inserted successfully\n";
                return;
            }

            if (table[newIndex] == key) {
                cout << "Duplicate key!\n";
                return;
            }
        }
        cout << "Hash table full!\n";
    }

    // SEARCH 

    void search(int key) {
        int index = hash1(key);

        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;

            if (table[newIndex] == key) {
                cout << "Key found\n";
                return;
            }
            if (table[newIndex] == -1)
                break;
        }
        cout << "Key not found\n";
    }

    // DELETE 

    void deleteKey(int key) {
        int index = hash1(key);

        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;

            if (table[newIndex] == key) {
                table[newIndex] = -2; // Mark as deleted
                cout << "Key deleted\n";
                return;
            }
            if (table[newIndex] == -1)
                break;
        }
        cout << "Key not found\n";
    }

    //  DISPLAY 

    void display() {
        cout << "\nHash Table (Probing Methods):\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (table[i] == -1)
                cout << "EMPTY";
            else if (table[i] == -2)
                cout << "DELETED";
            else
                cout << table[i];
            cout << endl;
        }

        cout << "\nHash Table (Chaining):\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            for (int x : chain[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key, method;

    do {
        cout << "\n--- HASH TABLE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Choose collision method:\n";
            cout << "1. Chaining\n2. Linear Probing\n3. Quadratic Probing\n4. Double Hashing\n";
            cin >> method;
            ht.insert(key, method);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.deleteKey(key);
            break;

        case 4:
            ht.display();
            break;
        }
    } while (choice != 0);

    return 0;
}