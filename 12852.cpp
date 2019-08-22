#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

pair<int, int> dp[1000002]; // {min, before}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n;
    dp[1] = {1,-1}; dp[2] = {1,1}; dp[3] = {1,1};
    
    for(int i = 4; i <= n; ++i) {
        dp[i] = {i,i};
        if((i&1) == 0)
            if(dp[i].fi > dp[i/2].fi) { dp[i].fi = dp[i/2].fi; dp[i].se = i/2; }
        if(i % 3 == 0)
            if(dp[i].fi > dp[i/3].fi) { dp[i].fi = dp[i/3].fi; dp[i].se = i/3; }
        if(dp[i].fi > dp[i-1].fi) { dp[i].fi = dp[i-1].fi; dp[i].se = i-1; }
        ++dp[i].fi;
    }
    
    k = n;
    cout << dp[n].fi << '\n';
    while(dp[k].se != -1) {
        cout << k << ' ';
        k = dp[k].se;
    }
    cout << 1;
}