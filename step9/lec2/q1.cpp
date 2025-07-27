#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string infixToPostfix(string expression) {
        stack<char> st;
        string result = "";
        for (char c : expression) {
            if (isalnum(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            } else if (isOperator(c)) {
                while (!st.empty() && 
                      ((precedence(c) < precedence(st.top())) || 
                      (precedence(c) == precedence(st.top()) && c != '^')) && 
                      st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
