#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;++i)

int main() {
    int sum[4], v[4][4] = {};
    int N, s1, s2, s3;
    cin >> N;
    
    rep(i, 0, N) {
        cin >> s1 >> s2 >> s3;
        ++v[1][s1]; ++v[2][s2]; ++v[3][s3];
    }
    rep(i, 1, 4)
        sum[i] = v[i][1] + v[i][2] * 2 + v[i][3] * 3;
    
    int maxCnt = 0, maxi, maxNum[3];
    maxi = max(sum[1], max(sum[2], sum[3]));
    rep(i, 1, 4) 
        if(maxi == sum[i]) maxNum[maxCnt++] = i;
    
    int ans = maxNum[0];
    if(maxCnt == 2) {
        if(v[maxNum[1]][3] > v[maxNum[0]][3]) ans = maxNum[1];
        else if(v[maxNum[0]][3] == v[maxNum[1]][3]) {
            if(v[maxNum[1]][2] > v[maxNum[0]][2]) ans = maxNum[1];
            else if(v[maxNum[0]][2] == v[maxNum[1]][2]) ans = 0;
        }
    }
    else if(maxCnt == 3) {
        if(v[maxNum[2]][3] > v[ans][3]) ans = maxNum[2];
        else if(v[maxNum[0]][3] == v[maxNum[1]][3]) {
            if(v[maxNum[2]][2] > v[maxNum[1]][2]) ans = maxNum[2];
            else if(v[maxNum[0]][2] == v[maxNum[1]][2]) ans = 0;
        }
    }
    cout << ans << ' ' << maxi;
}