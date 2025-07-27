#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string prefixToInfix(string expression) {
        stack<string> st;
        for (int i = expression.size() - 1; i >= 0; i--) {
            char c = expression[i];
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string newExp = "(" + op1 + string(1, c) + op2 + ")";
                st.push(newExp);
            }
        }
        return st.top();
    }
};
