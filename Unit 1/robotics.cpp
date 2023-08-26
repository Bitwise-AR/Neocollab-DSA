#include <iostream>
using namespace std;
int findMinimum(int array[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (array[mid] > array[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return array[left];
}

int main() {
    int n;
    cin>>n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin>>array[i];
    }

    int minimum = findMinimum(array, n);
    cout << minimum;

    return 0;
}