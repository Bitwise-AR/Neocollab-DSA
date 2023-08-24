#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
void insertion(vector<double>& prices) {
    int n = prices.size();
    for (int i = 1; i < n; i++) {
        double key = prices[i];
        int j = i - 1;
        
        while (j >= 0 && prices[j] > key) {
            prices[j + 1] = prices[j];
            j--;
        }
        
        prices[j + 1] = key;

        cout << "After Iteration " << i << ": ";
        for (const double& price : prices) {
            cout << fixed <<setprecision(2)<<price << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<double> stockPrices(n);
    for (int i = 0; i < n; i++) {
        cin >> stockPrices[i];
    }
    cout<<"Initial order: ";
    for (int i = 0; i < n; i++) {
        cout << fixed <<setprecision(2)<< stockPrices[i] <<" ";
    }
    cout<<endl;
    insertion(stockPrices);

    cout << "Sorted order:";
    for (const double& price : stockPrices) {
        cout << fixed <<setprecision(2)<<price << " ";
    }
    cout << endl;
    
    return 0;
}