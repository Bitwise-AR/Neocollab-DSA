#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void calculateAnnualIncomes(const vector<float>& monthlyIncomes) {
    ofstream outFile("income.txt");
    if (!outFile) {
        cerr << "Error: Unable to open the file 'income.txt'" << endl;
        exit(1);
    }

    for (float monthlyIncome : monthlyIncomes) {
        float annualIncome = monthlyIncome * 12.0f;
        outFile << fixed << setprecision(1) << annualIncome << endl;
    }

    outFile.close();
}

int main() {
    int n;
    cin >> n;

    if (n > 50) {
        cout << "Exceeding limit!" << endl;
        return 0;
    }

    vector<float> monthlyIncomes(n);

    for (int i = 0; i < n; ++i) {
        cin >> monthlyIncomes[i];
    }

    calculateAnnualIncomes(monthlyIncomes);

    ifstream inFile("income.txt");
    if (!inFile) {
        cerr << "Error: Unable to open the file 'income.txt'" << endl;
        return 1;
    }

    float annualIncome;
    while (inFile >> annualIncome) {
        cout << fixed << setprecision(1) << annualIncome << endl;
    }

    inFile.close();

    return 0;
}
