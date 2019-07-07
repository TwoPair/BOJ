#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;++i)

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int L, n;
    char c;
    cin >> L;
    
    while(L--) {
        cin >> n >> c;
        rep(i, 0, n) cout << c;
        cout << '\n';
    }
}