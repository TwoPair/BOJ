#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int minValue = 2e9, maxValue = -2e9;

int n;
vector<int> v;
int op[4] = { 0 };

void dfs(int idx, int tmpResult) {
    if (idx == n) {
        minValue = min(minValue, tmpResult);
        maxValue = max(maxValue, tmpResult);
        return;
    }

    if (op[0]) {    // +
        op[0]--;
        dfs(idx + 1, tmpResult + v[idx]);
        op[0]++;
    }
    if (op[1]) {    // -
        op[1]--;
        dfs(idx + 1, tmpResult - v[idx]);
        op[1]++;
    }
    if (op[2]) {    // x
        op[2]--;
        dfs(idx + 1, tmpResult * v[idx]);
        op[2]++;
    }
    if (op[3]) {   // div
        op[3]--;
        if (tmpResult < 0)
            dfs(idx + 1, -(-tmpResult / v[idx]));
        else
            dfs(idx + 1, tmpResult / v[idx]);
        op[3]++;
    }
}

int main() {
    fastio
    cin >> n;

    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int & i : op) {
        cin >> i;
    }

    dfs(1, v[0]);
    cout << maxValue << "\n" << minValue;
}
