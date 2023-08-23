#include <iostream>
#include <vector>
using namespace std;
vector<int> modify(vector<int> arr) {
    int n = arr.size();
    if (n == 0) {
        return {};
    }

    vector<int> res(n, 0);

    if (n == 1) {
        res[0] = arr[0] * arr[0];
    } else {
        res[0] = arr[0] * arr[1];
        res[n - 1] = arr[n - 1] * arr[n - 2];

        for (int i = 1; i < n - 1; ++i) {
            res[i] = arr[i - 1] * arr[i + 1];
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for (int i = 0; i < n; ++i) {
        cin >> ele[i];
    }

    vector<int> narr = modify(ele);
    for (int num : narr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
