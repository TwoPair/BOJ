#include <bits/stdc++.h>
using namespace std;

int len1, len2, dp[1001][1001];
string s1, s2;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    s1 = "0" + s1; s2 = "0" + s2;
    len1 = s1.size(); len2 = s2.size();
    
    for(int i = 1; i < len1; ++i)
        for(int j = 1; j < len2; ++j) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    cout << dp[len1-1][len2-1];
}