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
#define MAX 1000001
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

VI v(2 * MAX);
int a[MAX], b[MAX];

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    
    merge(a, a+n, b, b+m, v.begin());
    sort(v.begin(), v.begin()+n+m);
    rep(i,0,n+m) cout << v[i] << ' ';
}