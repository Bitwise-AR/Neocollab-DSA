#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &heights)
{
    int n = heights.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (heights[j] < heights[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(heights[i], heights[minIndex]);
        }
        cout << "Height order of students after iteration " << i + 1 << ": ";
        for (const int &height : heights)
        {
            cout << height << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout<<"Student's height order before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << height[i]<<" ";
    }
    cout<<endl;
    selectionSort(height);
    cout<<"After final comparison of all students, the height order becomes: ";
    for (const int &height : height)
    {
        cout << height << " ";
    }
    cout << endl;
    return 0;
}