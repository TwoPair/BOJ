#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;++i)
#define per(i,a,n) for (int i=n-1;i>=a;--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef map<int,int> MII;
// head

int n, m;
MII visited;
VI v;

void dfs() {
    if(sz(v) == m) {
        rep(i, 0, m) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(auto &i : visited) {
    	v.pb(i.fi);
        dfs();
        v.pop_back();
    }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int num;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> num;
        visited.insert({num, 1});
    }
    dfs();
}