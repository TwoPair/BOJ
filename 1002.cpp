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
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    PII x, y, r;
    int q;
    cin >> q;
    
    while(q--) {
        int ans = 0, add, sub, d;
        cin >>x.fi>>y.fi>>r.fi >>x.se>>y.se>>r.se;
        add = (r.fi + r.se)*(r.fi + r.se);
        sub = (r.fi - r.se)*(r.fi - r.se);
        d = (x.fi - x.se)*(x.fi - x.se) + (y.fi - y.se)*(y.fi - y.se);
        
        if(sub < d && d < add) ans = 2;
        else if(sub == d || add == d) ans = 1;
        if(d == 0 && r.fi == r.se) ans = -1;
        
        cout << ans << '\n';
    }
}