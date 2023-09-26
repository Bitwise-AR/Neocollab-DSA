#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> evenArr, oddArr;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenArr.push_back(arr[i]);
        } else {
            oddArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < evenArr.size(); i++) {
        cout << evenArr[i] << " ";
    }

    for (int i = 0; i < oddArr.size(); i++) {
        cout << oddArr[i] << " ";
    }

    cout << endl;

    return 0;
}
