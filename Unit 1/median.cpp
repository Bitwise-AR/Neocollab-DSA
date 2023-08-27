#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<vector<int>, double> mergeAndFindMedian(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> mergedArray;
    mergedArray.reserve(arr1.size() + arr2.size());
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(mergedArray));
    int totalSize = mergedArray.size();
    double median;
    if (totalSize % 2 == 0) {
        int middleIdx1 = totalSize / 2 - 1;
        int middleIdx2 = totalSize / 2;
        median = (mergedArray[middleIdx1] + mergedArray[middleIdx2]) / 2.0;
    } else {
        int middleIdx = totalSize / 2;
        median = mergedArray[middleIdx];
    }

    return make_pair(mergedArray, median);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }
    vector<int> arr2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }
    pair<vector<int>, double> result = mergeAndFindMedian(arr1, arr2);
    cout << result.second << endl;

    return 0;
}
