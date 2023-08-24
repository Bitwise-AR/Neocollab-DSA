#include <iostream>
using namespace std;
bool search(const int *arr, int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int n;
    cin >> n;

    int *ele = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> ele[i];
    }

    int item;
    cin >> item;

    bool found = search(ele, n, item);

    if (found) {
        cout << "Item found" << endl;
    } else {
        cout << "Item not found" << endl;
    delete[] ele;
    }
    return 0;
}
