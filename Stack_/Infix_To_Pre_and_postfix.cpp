#include "Infix_To_Pre_and_postfix.h"
#include <stack>
#include <algorithm>

template<class T>
bool isOperator(T c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

template<class T>
int precedence(T op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

template<class T>
string infixToPostfix(const string& infix) {
    stack<T> operators;
    string postfix = "";

    for (T c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
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

template<class T>
string infixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (T& c : reversedInfix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string postfix = infixToPostfix<T>(reversedInfix);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}
