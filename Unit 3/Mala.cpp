#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> operators;

    for (char c : infix) {
        if (c == ' ')
            continue;

        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard '('
        } else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}