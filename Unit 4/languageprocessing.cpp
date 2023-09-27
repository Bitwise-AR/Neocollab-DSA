#include <iostream>
#include <vector>
#include <string>

using namespace std;
int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    quickSort(words, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << words[i] << " ";
    }

    cout << endl;

    return 0;
}
