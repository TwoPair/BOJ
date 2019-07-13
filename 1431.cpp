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

string s[1002];

int sumInt(const string &c) {
    int sum = 0;
    rep(i, 0, sz(c))
        if('1' <= c[i] && c[i] <= '9')
            sum += (c[i] - '0');
    return sum;
}

bool cmp(const string &a, const string &b) {
    if(sz(a) != sz(b)) return sz(a) < sz(b);
    int sa = sumInt(a), sb = sumInt(b);
    if(sa != sb) return sa < sb;
    return a < b;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int n;
    cin >> n;
    rep(i, 0, n) cin >> s[i];
    
    sort(s, s + n, cmp);
    rep(i, 0, n) cout << s[i] << '\n';
}