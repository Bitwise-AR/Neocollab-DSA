#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        heapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int findKthSmallest(vector<int> &arr, int k)
{
    if (k <= 0 || k > arr.size())
        return -1;

    int kthSmallest = arr[k - 1];

    return kthSmallest;
}

int main()
{
    int n;
    cin >> n;

    if (n < 1 || n > 1000)
    {
        cout << "Invalid entry" << endl;
        return 0;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid entry" << endl;
        return 0;
    }
    else
    {
        buildMinHeap(arr);

        cout << "Min heap is: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    int kthSmallest = findKthSmallest(arr, k);

    cout << "The smallest crystal's size is " << kthSmallest << endl;

    return 0;
}