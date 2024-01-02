#include <iostream>
using namespace std;
typedef long long ll;

ll dp[91][2];
int n;

int main() {
    cin >> n;

    // init
    dp[1][0] = 0;
    dp[1][1] = 1;

    // do dp
    for (int step = 2; step <= n; ++step) {
        dp[step][0] = dp[step - 1][0] + dp[step - 1][1];
        dp[step][1] = dp[step - 1][0];
    }

    cout << dp[n][0] + dp[n][1];
}