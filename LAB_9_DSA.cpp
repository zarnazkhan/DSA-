#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

// Insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 0, choice;
    int arr[100];

    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Enter elements in array" << endl;
        cout << "2. Bubble Sort " << endl;
        cout << "3. Selection Sort " << endl;
        cout << "4. Insertion Sort " << endl;
        cout << "5. Display current array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            break;

        case 2:
            cout << "Before Sorting: "; display(arr, n);
            bubbleSort(arr, n);
            cout << "After Bubble Sort: "; display(arr, n);
            break;

        case 3:
            cout << "Before Sorting: "; display(arr, n);
            selectionSort(arr, n);
            cout << "After Selection Sort: "; display(arr, n);
            break;

        case 4:
            cout << "Before Sorting: "; display(arr, n);
            insertionSort(arr, n);
            cout << "After Insertion Sort: "; display(arr, n);
            break;

        case 5:
            display(arr, n);
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}