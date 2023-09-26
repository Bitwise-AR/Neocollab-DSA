#include <iostream>
#include <vector>
using namespace std;

int maximumLoot(int n, vector<int>& money, int currentHouse) {
    if (currentHouse >= n) {
        return 0;
    }

    int loot1 = money[currentHouse] + maximumLoot(n, money, currentHouse + 2);
    int loot2 = maximumLoot(n, money, currentHouse + 1);

    return max(loot1, loot2);
}

int main() {
    int n;
    cin >> n;
    vector<int> money(n);

    for (int i = 0; i < n; ++i) {
        cin >> money[i];
    }

    int maxLoot = maximumLoot(n, money, 0);
    cout << maxLoot << endl;

    return 0;
}
