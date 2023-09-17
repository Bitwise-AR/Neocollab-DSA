#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    double sum = 0;

    for (int i = 0; i < n; ++i) {
        int ele;
        cin >> ele;
        s.push(ele);
        sum += ele;

        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;

        if (!s.empty()) {
            double average = sum / s.size();
            cout << fixed << setprecision(2) << "Average of the stack values: " << average << endl;
        }
    }

    while (!s.empty()) {
        int poppedValue = s.top();
        s.pop();
        cout << "Popped value: " << poppedValue << endl;

        if (!s.empty()) {
            sum -= poppedValue;
            double average = sum / s.size();
            cout << fixed << setprecision(2) << "Average of the stack values: " << average << endl;
        }
    }

    return 0;
}
