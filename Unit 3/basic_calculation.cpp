#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double sum = a + b;
    double product = b * c;

    ofstream outputFile("operations.txt");
    outputFile << fixed << setprecision(2) << sum << endl;
    outputFile << fixed << setprecision(2) << product << endl;
    outputFile.close();

    ifstream resultFile("operations.txt");
    double resultSum, resultProduct;
    resultFile >> resultSum >> resultProduct;
    resultFile.close(); 

    cout << resultSum << endl;
    cout << resultProduct << endl;

    return 0;
}