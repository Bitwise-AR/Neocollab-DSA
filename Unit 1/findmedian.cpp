#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMedian(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[rows - 1][cols - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count the number of elements less than or equal to mid in the matrix
        for (int i = 0; i < rows; ++i) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < (rows * cols) / 2 + 1) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int median = findMedian(matrix);
    cout << median << endl;

    return 0;
}