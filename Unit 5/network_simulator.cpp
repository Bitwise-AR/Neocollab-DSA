#include <iostream>
#include <vector>

using namespace std;

void minHeapify(vector<int> &heap, int n, int index) {
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

void convertMinToMaxHeap(vector<int> &heap) {
    int n = heap.size();

    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> minHeap(n);

    for (int i = 0; i < n; i++) {
        cin >> minHeap[i];
    }

    convertMinToMaxHeap(minHeap);

    cout << "The max heap array after conversion: ";
    for (int i = 0; i < n; i++) {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    cout << "The largest element is " << minHeap[0] << endl;

    return 0;
}
