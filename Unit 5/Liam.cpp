#include <iostream>
#include <vector>

using namespace std;

const int maxSize = 100;

void maxHeapify(vector<int> &heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap.size() && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void insertIntoMaxHeap(vector<int> &heap, int task)
{
    if (heap.size() == maxSize)
    {
        cout << "Heap is already at maximum capacity." << endl;
        return;
    }

    heap.push_back(task);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] < heap[index])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    maxHeapify(heap, index);
}

int main()
{
    vector<int> maxHeap;
    int task;

    cout << "Enter tasks (space-separated integers): ";
    while (cin >> task)
    {
        insertIntoMaxHeap(maxHeap, task);
    }

    cout << "Max Heap after inserting tasks: ";
    for (int i = 0; i < maxHeap.size(); i++)
    {
        cout << maxHeap[i] << " ";
    }

    cout << endl;

    return 0;
}
