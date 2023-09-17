#include <iostream>
#include <deque>
#include <string>
using namespace std;

void findPatternOccurrences(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << "Pattern is longer than the string" << endl;
        return;
    }

    deque<int> indexes;

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            indexes.push_back(i);
        }
    }

    if (indexes.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        for (int index : indexes) {
            cout << "Pattern found at index " << index << endl;
        }
    }
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    findPatternOccurrences(text, pattern);

    return 0;
}
