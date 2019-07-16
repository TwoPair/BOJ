#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;++i)
#define per(i,a,n) for (int i=n-1;i>=a;--i)
// head

string num;
int n[11];

void parse() { for(auto c : num) ++n[c - '0']; }

void solve() {
    int sum = 0;
    if(n[0] == 0) { cout << -1; return; }
    
    rep(i, 1, 10) if(n[i] != 0) sum += i * n[i];
    if(sum % 3 != 0) { cout << -1; return; }
    else per(i, 0, 10) rep(j, 0, n[i]) cout << i;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    cin >> num;
    parse(); solve();
}