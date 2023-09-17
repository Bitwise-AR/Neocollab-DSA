#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        dq.push_back(element);
    }

    bool printAlternate = true;

    for (int i = 0; i < N; i++) {
        if (printAlternate) {
            cout << dq.front() << " ";
        }
        dq.pop_front();
        printAlternate = !printAlternate;
    }

    cout << endl;

    return 0;
}
