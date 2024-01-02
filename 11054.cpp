#include <iostream>
#include <algorithm>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int N;
vector<int> v;
vector<int> dp[2];

// LIS; Longest Increasing Subsequence
void findLIS(int step) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] > v[j] && dp[step][i] < dp[step][j] + 1)
                dp[step][i] = dp[step][j] + 1;
}

int findLongestBitonic() {
    int maxBitonic = 0;
    for (int i = 0; i < N; ++i) {
        int cmp = dp[0][i] + dp[1][N - i - 1] - 1;
        maxBitonic = max(maxBitonic, cmp);
    }

    return maxBitonic;
}

int main() {
    fastio
    cin >> N;
    v.resize(N);
    dp[0].resize(N, 1);
    dp[1].resize(N, 1);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    // do dp
    findLIS(0);
    std::reverse(v.begin(), v.end());
    findLIS(1);

    // find max bitonic sequence
    cout << findLongestBitonic();
}