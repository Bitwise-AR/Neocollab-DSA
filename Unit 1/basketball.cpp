#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    selectionSort(heights, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << heights[i] << " ";
    }
    cout << endl;
    cout << "The Second largest element is " << heights[1] << endl;

    return 0;
}