#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    
    int max_size = (n > m) ? n : m;
    int merged[max_size];
    for (int i = 0; i < max_size; ++i) {
        int num1 = (i < n) ? arr1[i] : 0;
        int num2 = (i < m) ? arr2[i] : 0;
        merged[i] = num1 + num2;
    }
    
    for (int i = max_size - 1; i >= 0; --i) {
        cout << merged[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
