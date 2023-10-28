#include <iostream>
#include <vector>

using namespace std;

bool isMinHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2 * i + 1]) {
            return false;
        }
        
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    if (isMinHeap(weights)) {
        cout << "The players are arranged in min heap order" << endl;
    } else {
        cout << "The players are not arranged in min heap order" << endl;
    }
    
    return 0;
}
