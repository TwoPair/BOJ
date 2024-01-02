#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

stack<char> o;
string str;   // max length: 100

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

void doOperator(char op) {
    if (op == '+' || op == '-') {
        while (!o.empty()) {
            char t = o.top();
            if (t == '(') {
                break;
            } else {
                    cout << t;
                    o.pop();
            }
        }
        o.push(op);
    } else if (op == '*' || op == '/') {
        while (!o.empty()) {
            char t = o.top();
            if (t == '(' || t == '+' || t == '-') {
                break;
            } else if (t == '*' || t == '/') {
                cout << t;
                o.pop();
            }
        }
        o.push(op);
    } else if (op == '(') {
        o.push(op);
    } else if (op == ')') {
        while (!o.empty()) {
            char t = o.top();
            if (t == '(') {
                o.pop();
                break;
            } else {
                cout << t;
                o.pop();
            }
        }
    }
}

void postfixNotation() {
    for (auto c: str) {
        if (isOperator(c))
            doOperator(c);
        else
            cout << c;
    }

    while (!o.empty()) {
        cout << o.top();
        o.pop();
    }
}

int main() {
    fastio
    cin >> str;

    postfixNotation();
}