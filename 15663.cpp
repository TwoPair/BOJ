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
typedef long long ll;
typedef map<int,int> MII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
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
    	if(i.se != 0) {
	        --i.se; v.pb(i.fi);
	        dfs();
	        ++i.se; v.pop_back();
    	}
    }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int num;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> num;
        if(visited.find(num) != visited.end()) ++visited[num];
        else visited.insert({num, 1});
    }
    dfs();
}