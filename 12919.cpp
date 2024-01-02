#include <iostream>
#include <string>
using namespace std;

string s, t;
bool result = false;

void dfs(int start, int end, int next, int diff_len) {
    if (result) return;

    if (diff_len == 0) {
        string tmp;
        if (start > end) {
            tmp = t.substr(end, start - end + 1);
            reverse(tmp.begin(), tmp.end());
        } else {
            tmp = t.substr(start, end - start + 1);
        }

        result = (s == tmp);
        return;
    }

    if (t[start] == 'B') {  // BA, BB
        int nxt = next;
        dfs(end, start + next, -nxt, diff_len - 1);
    }

    if (t[end] == 'A')      // AA, BA
        dfs(start, end - next, next, diff_len - 1);

    if (t[start] == 'A' && t[end] == 'B')   // AB
        dfs(start, end, next, 0);
}

int main() {
    cin >> s >> t;

    int diff_len = t.length() - s.length();
    int start = 0, end = (int)t.length() - 1;
    int next = 1;

    dfs(start, end, next, diff_len);

    cout << result;
}