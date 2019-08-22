#include <cstdio>

long long dp[36];

int main() {
    int n, mid;
    scanf("%d", &n);
    dp[0] = 1; dp[1] = 1;
    
    for(int i = 2; i <= n; ++i) {
        mid = i / 2;
        for(int j = 0; j < mid; ++j) dp[i] += 2*dp[j]*dp[i-j-1];
        if(i&1) dp[i] += dp[mid]*dp[mid];
    }
    
    printf("%lld", dp[n]);
}