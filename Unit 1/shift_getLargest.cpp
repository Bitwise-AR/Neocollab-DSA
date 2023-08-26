#include <iostream>

void shift(int &a, int &b, int &c)
{
    int temp = c;
    c = b;
    b = a;
    a = temp;
}
int &getLargest(int &a, int &b, int &c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    else if (b >= a && b >= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int newLargest;
    std::cin >> newLargest;
    std::cout << "Before Shift x: " << x << " y: " << y << " z: " << z << std::endl;
    shift(x, y, z);
    std::cout << "After shift x: " << x << " y: " << y << " z: " << z << std::endl;
    int &largest = getLargest(x, y, z);
    

    largest = newLargest;

    std::cout << "After modification x: " << x << " y: " << y << " z: " << z << std::endl;
    std::cout << "The largest value among x, y, and z is: " << largest << std::endl;

    return 0;
}