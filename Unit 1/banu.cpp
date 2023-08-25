#include <iostream>
using namespace std;
int coutele(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= key) {
            result = mid; 
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result + 1;
}

int main() {
    int size;
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    
    int key;
    cin >> key;
    
    int count = coutele(arr, size, key);
    cout << count << endl;
    
    return 0;
}
