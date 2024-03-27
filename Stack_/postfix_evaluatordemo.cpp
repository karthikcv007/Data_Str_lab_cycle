#include "postfix_evaluator.cpp"
#include <iostream>
#include <string>

int main() {
    PostfixEvaluator evaluator;
    std::string exp;
    
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, exp);
    
    std::cout << "Postfix evaluation: " << evaluator.evaluatePostfix(exp) << std::endl;
    return 0;
}
