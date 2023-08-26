#include <iostream>

int findSmallestMissing(int arr[], int size, int x) {
    int left = 0, right = size - 1;
    int result = -1;  
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x && (mid == 0 || arr[mid - 1] > arr[mid] - 1)) {
            result = arr[mid] - 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    if (result == -1) {
        result = x + 1;
    }
    
    return result;
}
int main() {
    int size;
    std::cin >> size;

    int arr[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int x;
    std::cin >> x;

    int smallestMissing = findSmallestMissing(arr, size, x);
    std::cout << "The smallest missing positive integer greater than " << x << " is " << smallestMissing << "." << std::endl;

    return 0;
}