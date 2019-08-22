#include <cstdio>
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define max(a,b) (a>b?a:b)

int gr[10001], dp[10001];

int main() { // 현재의 것을 무조건 마실 필요는 없다
    int n; scanf("%d", &n);
    rep(i,1,n) scanf("%d", gr + i);
    
    dp[1] = gr[1];
    dp[2] = gr[1]+gr[2];
    rep(i,3,n) dp[i] = max(max(gr[i-1]+dp[i-3]+gr[i], dp[i-2]+gr[i]), dp[i-1]);
    
    printf("%d", dp[n]);
}