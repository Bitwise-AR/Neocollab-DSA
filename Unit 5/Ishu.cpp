#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at a given index
void maxHeapify(vector<char>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max Heap from an array of characters
void buildMaxHeap(vector<char>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to perform Heap Sort on an array of characters
void heapSort(vector<char>& arr) {
    int n = arr.size();

    // Build a max heap
    buildMaxHeap(arr);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> grades(n);
    for (int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    heapSort(grades);

    for (int i = 0; i < n; i++) {
        cout << grades[i];
        if (i < n - 1) {
            cout << " ";
        }
    }

    return 0;
}
