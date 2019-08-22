#include <bits/stdc++.h>
using namespace std;

int rvs_num(int n) {
    int cp = n, rvs = 0;
    while(n != 0) {
        rvs = rvs * 10 + n % 10;
        n /= 10;
    }
    return cp + rvs;
}

bool isSym(const string &n) {
    int sz = n.size();
    for(int i = 0; i < sz / 2; ++i)
        if(n[i] != n[sz - 1 - i]) return false;
    return true;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int T, n; cin >> T;
    while(T--) {
        cin >> n;
        if(isSym(to_string(rvs_num(n)))) cout << "YES\n";
        else cout << "NO\n";
    }
}