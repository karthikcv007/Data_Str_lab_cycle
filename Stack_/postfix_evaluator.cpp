#include "postfix_evaluator.h"

int PostfixEvaluator::evaluatePostfix(std::string exp) {
    std::stack<int> st;
    
    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i]) {
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
            }
        }
    }
    return st.top();
}
