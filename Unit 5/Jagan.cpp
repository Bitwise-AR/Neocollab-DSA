#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& heap, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(heap, n, i);
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << "Invalid entry" << endl;
        return 1;
    }

    vector<int> taskRunningTimes(n);

    for (int i = 0; i < n; i++) {
        cin >> taskRunningTimes[i];
    }

    buildMaxHeap(taskRunningTimes);

    for (int i = 0; i < n; i++) {
        cout << taskRunningTimes[i] << " ";
    }
    cout << endl;

    return 0;
}
