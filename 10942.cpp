// Dynamic Programming : O(n^2)
#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int N;
vector<vector<int>> dp;
vector<int> v;

// dp[][] = 1 ->     palindrome
// dp[][] = 0 -> not palindrome
void init() {
    // (odd) self is palindrome.
    for (int i = 0; i < N; ++i)
        dp[i][i] = 1;

    // (even) two elements nearby are palindrome if they are same
    for (int i = 0; i < N - 1; ++i) {
        if (v[i] == v[i + 1])
            dp[i][i + 1] = 1;
    }

    // sliding window) check k sizes of number lists
    for (int k = 2; k < N; ++k) {
        for (int i = 0; i < N - k; ++i) {
            int j = i + k;
            if (v[i] == v[j] && dp[i + 1][j - 1] == 1)
                dp[i][j] = 1;
        }
    }
}

int main() {
    fastio
    cin >> N;
    v.resize(N + 1);
    dp.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    int m; cin >> m;

    init();
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s - 1][e - 1] << "\n";
    }
}