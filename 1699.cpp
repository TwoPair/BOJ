#include <iostream>
#include <cmath>
using namespace std;

int dp[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) dp[i] = i;
    for (int i = 1; i <= (int)sqrt(n); i++) {
        int idx = i * i;
        if (idx <= n)
            dp[idx] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j)
            dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
    }

    cout << dp[n];
}