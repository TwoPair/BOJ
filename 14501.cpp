#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, dp[16];
vector<pair<int, int>> schedule;

void solve() {
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i < schedule[i].first)
            dp[i] = dp[i - 1];
        else
            dp[i] = max(dp[i - 1], schedule[i].second + dp[i - schedule[i].first]);
    }
}

int main() {
    cin >> n;

    int t, p;
    for (int i = 0; i < n; ++i) {
        cin >> t >> p;
        schedule.push_back({t, p});
    }
    schedule.push_back({0, 0});
    reverse(schedule.begin(), schedule.end());

    solve();
    cout << dp[n];
}