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
#define MAX 100002
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n, m;
int accum[MAX];

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int tmp, s, e;
    cin >> n;
    rep(i, 1, n+1) { cin >> tmp; accum[i] = accum[i-1] + tmp; }
    cin >> m;
    rep(i, 0, m) {
        cin >> s >> e;
        cout << accum[e] - accum[s-1] << '\n';
    }
}