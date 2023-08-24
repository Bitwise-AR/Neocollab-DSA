#include <iostream>
#include <vector>
using namespace std;
int search(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid; 
        } else if (nums[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    
    return -1; 
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int target;
    cin >> target;

    int res = search(nums, target);
    
    if (res != -1) {
        cout << "Target found at index: " << res << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
