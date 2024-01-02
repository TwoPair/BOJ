#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX 200001
#define INF 987654321
using namespace std;

int n, k, result;
int dp[MAX];

/**
 * almost O(n) = 3^n. Too slow.
 */
void dfs(int now, int sec) {
    if (now < 0 || now > 100000 || now > k + abs(n - k)) return;
    if (sec >= result) return;

    if (now == k) {
        result = min(result, sec);
        return;
    }

    dfs(now * 2, sec);
    dfs(now + 1, sec + 1);
    dfs(now - 1, sec + 1);
}

/**
 * 다른 풀이로 가장 많이 사용했던 알고리즘이 "0-1 BFS"다.
 */

int main() {
    cin >> n >> k;

    /* DFS flow */
//    if (n >= k)
//        result = n - k;
//    else {
//        result = k - n;
//        dfs(n, 0);
//    }
//
//    cout << result;

    /* DP flow */
    // init
    for (int i = 0; i < MAX; ++i)
        dp[i] = INF;
    dp[0] = n;

    for (int i = 1; i < MAX; ++i) {
        if (i <= n) {
            dp[i] = n - i;
        } else {
            if (i % 2 == 0)
                dp[i] = min(min(dp[i - 1] + 1, dp[i + 1] + 1), dp[i / 2]);
            else
                dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
        }

        for (int j = i * 2; j < MAX; j *= 2)
            dp[j] = min(dp[j], dp[i]);
    }

    cout << dp[k];
}