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

int N, white, blue; // white = 0, blue = 1
int paper[130][130];

bool chkSame(int x, int y, int si) {
    int color = paper[x][y];
    rep(i, x, x + si) rep(j, y, y + si)
        if(color != paper[i][j])
            return false;
    
    if(color == 0) ++white;
    if(color == 1) ++blue;
    return true;
}

void cut(int x, int y, int si) {
    if(chkSame(x, y, si)) return;
    
    si >>= 1;
    cut(x, y, si); cut(x + si, y, si); cut(x, y + si, si); cut(x + si, y + si, si);
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> paper[i][j];
    cut(0, 0, N);
    
    cout << white << '\n' << blue;
}