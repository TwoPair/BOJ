#include <bits/stdc++.h>
using namespace std;

int len1, len2, dp[1001][1001];
string s1, s2, LCS;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    
    // 1. Calculate LCS's length
    s1 = "0" + s1; s2 = "0" + s2;
    len1 = s1.size(); len2 = s2.size();
    
    for(int i = 1; i < len1; ++i)
        for(int j = 1; j < len2; ++j) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    cout << dp[len1-1][len2-1] << '\n';
    
    // 2. Show one of cases of LCS
    int i = len1 - 1, j = len2 - 1;
    while(dp[i][j] != 0) {
        if(dp[i][j] == dp[i][j-1]) --j;
        else if(dp[i][j] == dp[i-1][j]) --i;
        else if(dp[i][j] - 1 == dp[i-1][j-1]) {
            LCS += s1[i];
            --i, --j;
        }
    }
    reverse(LCS.begin(), LCS.end());
    cout << LCS;
}