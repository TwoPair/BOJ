#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;++i)

int n, m;
string p[11];

int main() {
    scanf("%d%d", &n, &m); 
    rep(i,0,n) cin >> p[i];
    rep(i,0,n) reverse(p[i].begin(), p[i].end());
    rep(i,0,n) cout << p[i] << '\n';
}