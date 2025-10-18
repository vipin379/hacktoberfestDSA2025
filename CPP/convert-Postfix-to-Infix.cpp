#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If operand, push to stack
        if (isalnum(c)) {
            string op(1, c);
            st.push(op);
        }
        // If operator, pop two operands and combine
        else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }

    // Final expression
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
