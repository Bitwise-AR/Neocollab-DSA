#include <iostream>
#include <cmath>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance() {
        feet = 0;
        inches = 0.0;
    }

    Distance(int ft, float in) {
        feet = ft;
        inches = in;
    }

    void setDistance(int ft, float in) {
        feet = ft;
        inches = in;
    }

    void addDistance(Distance d1, Distance d2) {
        feet = d1.feet + d2.feet;
        inches = d1.inches + d2.inches;

        if (inches >= 12.0) {
            feet++;
            inches -= 12.0;
        }
    }

    void display() {
        cout << "distance = " << feet << "'" << inches << "\"" << endl;
    }
};

int main() {
    float feet, inches;
    cin >> feet >> inches;

    Distance d1(feet, inches);
    Distance d2 = d1;

    Distance d3;
    d3.addDistance(d1, d2);

    d3.display();

    return 0;
}