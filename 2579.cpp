#include <cstdio>
#define max(a,b) (a>b?a:b)

int st[301], dp[301];

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", st + i);
    
    dp[1] = st[1];
    dp[2] = max(st[1]+st[2], st[2]);
    dp[3] = max(st[1]+st[3], st[2]+st[3]);
    
    for(int i = 4; i <= n; ++i)
        dp[i] = max(st[i-1]+dp[i-3], dp[i-2]) + st[i];
    printf("%d", dp[n]);
}