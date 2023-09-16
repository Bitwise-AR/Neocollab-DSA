#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return isalnum(c);
}

string infixToPostfix(string expr) {
    stack<char> operators;
    string postfix = "";

    for (char &c : expr) {
        if (c == ' ') {
            continue; 
        } else if (isOperand(c)) {
            postfix += c; 
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
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
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string expr;
        getline(cin, expr);

        bool valid = true;
        stack<char> parentheses;
        for (char c : expr) {
            if (c == '(') {
                parentheses.push(c);
            } else if (c == ')') {
                if (parentheses.empty() || parentheses.top() != '(') {
                    valid = false;
                    break;
                }
                parentheses.pop();
            }
        }
        if (!parentheses.empty() || !valid) {
            cout << "Invalid expr" << endl;
            continue;
        }

        string postfix = infixToPostfix(expr);
        cout << "Postfix expr " << i << ": " << postfix << endl;
    }

    return 0;
}