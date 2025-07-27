#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string postfixToPrefix(string expression) {
        stack<string> st;
        for (char c : expression) {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string newExp = string(1, c) + op1 + op2;
                st.push(newExp);
            }
        }
        return st.top();
    }
};
