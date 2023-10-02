#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
    return 0;
}

string postfix(string infix) {
    string postfix = "";
    stack<char> st;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.pop();
        } else if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            st.push(infix[i]);
        } else {
            while (!st.empty() && precedence(infix[i])<=precedence(st.top())) {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty()) {
        char c = st.top();
        st.pop();
        postfix += c;
    }
    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);
    cout << postfix(infix);
    return 0;
}
