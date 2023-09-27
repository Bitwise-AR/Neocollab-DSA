#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

bool compare(int a, int b) {
    int countA = countSetBits(a);
    int countB = countSetBits(b);
    if (countA != countB) {
        return countA < countB;
    } else {
        return a < b;
    }
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (compare(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
