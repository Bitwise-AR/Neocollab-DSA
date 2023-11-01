#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at a given index
void maxHeapify(vector<int>& arr, int n, int i) {
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

// Function to build a Max Heap from an array
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to remove and print the maximum element from the Max Heap
int extractMax(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) {
        return -1; // Heap is empty
    }

    int maxVal = arr[0];
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    maxHeapify(arr, n - 1, 0);
    return maxVal;
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    vector<int> heap(n);

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    buildMaxHeap(heap);

    int maxElement = extractMax(heap);
    if (maxElement == -1) {
        cout << "Heap is empty." << endl;
    } else {
        cout << maxElement << endl;
    }

    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i];
        if (i < heap.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
