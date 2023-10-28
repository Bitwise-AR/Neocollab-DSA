#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxSize = 100;

void minHeapify(vector<int>& heap, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void insertDeliveryLocation(vector<int>& heap, int distance) {
    if (heap.size() == maxSize) {
        cout << "Heap is already at maximum capacity." << endl;
        return;
    }

    heap.push_back(distance);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    minHeapify(heap, heap.size(), index);
}

int main() {
    vector<int> minHeap;
    int distance;

    while (cin >> distance) {
        insertDeliveryLocation(minHeap, distance);
    }

    for (int i = 0; i < minHeap.size(); i++) {
        cout << minHeap[i] << " ";
    }

    cout << endl;

    return 0;
}
