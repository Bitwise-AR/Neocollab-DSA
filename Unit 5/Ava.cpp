#include <iostream>
#include <vector>

using namespace std;

const int maxSize = 100;

void maxHeapify(vector<int> &heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void insertJobProcessingTime(vector<int> &heap, int processingTime) {
    if (heap.size() == maxSize) {
        cout << "Heap is already at maximum capacity." << endl;
        return;
    }

    heap.push_back(processingTime);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    maxHeapify(heap, index);
}

int main() {
    vector<int> maxHeap;
    int processingTime;

    cout << "Enter job processing times (space-separated integers): ";
    while (cin >> processingTime) {
        insertJobProcessingTime(maxHeap, processingTime);
    }

    cout << "Max Heap after inserting job processing times: ";
    for (int i = 0; i < maxHeap.size(); i++) {
        cout << maxHeap[i] << " ";
    }

    cout << endl;

    return 0;
}
