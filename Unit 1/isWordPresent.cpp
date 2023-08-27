#include <iostream>
#include <string>
using namespace std;
bool isWordPresent(const string& sentence, const string& targetWord) {
    int sentenceLength = sentence.length();
    int targetLength = targetWord.length();

    for (int i = 0; i <= sentenceLength - targetLength; i++) {
        bool found = true;
        for (int j = 0; j < targetLength; j++) {
            if (sentence[i + j] != targetWord[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    return false;
}

int main() {
    string sentence;
    string targetWord;

    getline(cin, sentence);
    getline(cin, targetWord);

    if (isWordPresent(sentence, targetWord)) {
        cout << "The word '" << targetWord << "' is present in the given sentence." << endl;
    } else {
        cout << "The word '" << targetWord << "' is not present in the given sentence." << endl;
    }

    return 0;
}
