#include "Infix_To_Pre_and_postfix.cpp"

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix<char>(infix);
    string prefix = infixToPrefix<char>(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
