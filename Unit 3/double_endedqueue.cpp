#include <iostream>
#include <deque>
using namespace std;

int main() {
    int length, numDelete;
    cin >> length;

    deque<int> dq;

    for (int i = 0; i < length; i++) {
        int element;
        cin >> element;
        dq.push_front(element);
    }

    cin >> numDelete;

    if (dq.empty()) {
        cout << "The front element is -1." << endl;
    } else {
        cout << "The front element is " << dq.front() << "." << endl;

        for (int i = 0; i < numDelete; i++) {
            dq.pop_front();
        }

        if (dq.empty()) {
            cout << "After deletion, the front element becomes -1." << endl;
        } else {
            cout << "After deletion, the front element becomes " << dq.front() << "." << endl;
        }
    }

    return 0;
}
