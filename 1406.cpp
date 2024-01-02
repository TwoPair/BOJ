#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    fastio
    string s, cmd;
    int num_cmd;
    getline(cin, s);
    cin >> num_cmd;

    stack<char> left, right;

    // init
    for (char c : s)
        left.push(c);

    while (num_cmd--) {
        cin >> cmd;
        if (cmd == "L" && !left.empty()) {
            right.push(left.top());
            left.pop();
        } else if (cmd == "D" && !right.empty()) {
            left.push(right.top());
            right.pop();
        } else if (cmd == "B" && !left.empty()) {
            left.pop();
        } else if (cmd == "P") {
            char c;
            cin >> c;
            left.push(c);
        }
    }

    // print
    string result;
    while (!left.empty()) {
        result += left.top();
        left.pop();
    }
    reverse(result.begin(), result.end());
    while (!right.empty()) {
        result += right.top();
        right.pop();
    }
    cout << result;
}