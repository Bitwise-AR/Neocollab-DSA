#include <iostream>
#include <vector>
#include <string>
using namespace std;
int isFruitPresent(const vector<string>& fruits, const string& target) {
    int low = 0;
    int high = fruits.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (fruits[mid] == target) {
            result = mid;
            high = mid - 1; 
        }
        else if (fruits[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<string> fruitList;
    int numFruits;
    cin >> numFruits;
    for (int i = 0; i < numFruits; ++i) {
        string fruit;
        cin >> fruit;
        fruitList.push_back(fruit);
    }

    string target;
    cin >> target;

    int index = isFruitPresent(fruitList, target);

    if (index != -1) {
        cout << "The first occurrence of \"" << target << "\"" << " is at index " << index << "." << endl;
    } else {
        cout << "\"" << target << "\"" << " is not found in the array. " << endl;
    }

    return 0;
}