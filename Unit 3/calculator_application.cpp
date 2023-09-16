#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN(string expr) {
    stack<int> operands;

    istringstream iss(expr);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            operands.push(stoi(token)); 
        } else if (isOperator(token[0])) {
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();

            int res;
            switch (token[0]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            operands.push(res);
        }
    }

    return operands.top();
}

int main() {
    string expr;
    getline(cin, expr);

    int res = RPN(expr);

    cout << "The result is: " << res << endl;

    return 0;
}