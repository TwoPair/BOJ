#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int N;
vector<int> v;
vector<int> dp;

// LIS; Longest Increasing Subsequence
void findLIS() {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] > v[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
}

void findLongest() {
    deque<int> d;
    int maxLIS = *max_element(dp.begin(), dp.end());
    int last = -1;

    cout << maxLIS << "\n";

    for (int i = N - 1; i >= 0 && maxLIS > 0; --i) {
        if (dp[i] == maxLIS) {
            if (last == -1 || last > v[i])
                last = v[i];
            maxLIS--;
            d.push_front(last);
        }
    }

    for (auto i: d)
        cout << i << " ";
}

int main() {
    fastio
    cin >> N;
    v.resize(N);
    dp.resize(N, 1);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    // do dp
    findLIS();

    // find LIS length & sequence
    findLongest();
}