#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int N;
vector<int> v;
vector<int> dp;

// LDS; Longest Decreasing Subsequence
void findLDS() {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] < v[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
}

int findLongest() {
    return *max_element(dp.begin(), dp.end());
}

int main() {
    fastio
    cin >> N;
    v.resize(N);
    dp.resize(N, 1);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    // do dp
    findLDS();

    // find max bitonic sequence
    cout << findLongest();
}
