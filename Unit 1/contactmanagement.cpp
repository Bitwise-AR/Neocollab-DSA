#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertionSort(vector<string>& contacts) {
    int n = contacts.size();
    for (int i = 1; i < n; ++i) {
        string key = contacts[i];
        int j = i - 1;
        
        while (j >= 0 && contacts[j] > key) {
            contacts[j + 1] = contacts[j];
            j = j - 1;
        }
        
        contacts[j + 1] = key;
        cout << "After Insertion " << i << ": ";
        for (int k = 0; k < n; ++k) {
            cout<< contacts[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> contacts(n);
    for (int i = 0; i < n; ++i) {
        cin >> contacts[i];
    }
    cout << "Initial order: ";
    for (int i = 0; i < n; ++i) {
        cout << contacts[i] << " ";
    }
    cout << endl;
    insertionSort(contacts);

    cout << "Sorted order: ";
    for (int i = 0; i < n; ++i) {
        cout << contacts[i] << " ";
    }
    cout << endl;

    return 0;
}