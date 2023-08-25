#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string add(const string& inp_type, const string& arg1, const string& arg2 = "", const string& arg3 = "") {
    if (inp_type == "str") {
        return arg1 + arg2 + arg3;
    } else {
        return "Invalid input type for string concatenation";
    }
}

int add(const string& inp_type, int arg1, int arg2 = 0, int arg3 = 0) {
    if (inp_type == "int") {
        return arg1 + arg2 + arg3;
    } else {
        return -1;
    }
}

int main() {
    string inp_type;
    int inp1, inp2, inp3;

    cin >> inp_type;

    if (inp_type == "str") {
        string arg1, arg2, arg3;
        cin >> arg1 >> arg2 >> arg3;

        string result = add(inp_type, arg1);
        cout << result << endl;

        result = add(inp_type, arg1, arg2);
        cout << result << endl;

        result = add(inp_type, arg1, arg2, arg3);
        cout << result << endl;
    } else if (inp_type == "int") {
        cin >> inp1 >> inp2 >> inp3;

        int result = add(inp_type, inp1);
        cout<< result << endl;

        result = add(inp_type, inp1, inp2);
        cout << result << endl;

        result = add(inp_type, inp1, inp2, inp3);
        cout << result << endl;
    } else {
        cout << "Invalid input type" << endl;
    }

    return 0;
}
