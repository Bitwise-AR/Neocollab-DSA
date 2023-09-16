#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}

string infixToRPN(string infix) {
    stack<char> operators;
    stringstream output;
    stringstream input(infix);
    string token;

    while (input >> token) {
        if (isdigit(token[0])) {
            output << token << " ";
        } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token[0])) {
                output << operators.top() << " ";
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    while (!operators.empty()) {
        output << operators.top() << " ";
        operators.pop();
    }

    return output.str();
}

int main() {
    string expr;
    getline(cin, expr);

    string rpn = infixToRPN(expr);

    cout << "The Reverse Polish Notation (RPN) expression is: " << rpn << endl;

    return 0;
}
