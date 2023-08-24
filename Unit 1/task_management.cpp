#include <iostream>

int findSmallestMissing(int arr[], int size, int x) {
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
    std::cout << "The smallest missing positive integer greater than " << x << " is: " << smallestMissing << std::endl;

    return 0;
}
