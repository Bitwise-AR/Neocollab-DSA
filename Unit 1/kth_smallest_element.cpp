#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &cost)
{
    int n = cost.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (cost[j] < cost[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(cost[i], cost[minIndex]);
        }
    }
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> ticket(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ticket[i];
    }
    cin >> k;
    selectionSort(ticket);
    cout << "Sorted order: ";
    for (const int &price : ticket)
    {
        cout << price << " ";
    }
    cout << endl;
    cout << "The kth smallest element is: " << ticket[k - 1] << endl;
    return 0;
}