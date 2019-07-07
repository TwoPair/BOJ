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

int N, M, cnt, start = 0; // start는 index 기준 정수
VI lc;
deque<int> d;

int solve(int pos) {
    int size = sz(d), idx = start, len;
    while(true) {// 2번 연산 횟수
        if(d[idx] == pos)
            break;
        idx = (idx + 1) % size;
    }
    len = abs(start - idx);
    len = min(len, size - len);
    
    start = idx;
    d.erase(d.begin() + idx);
    
    return len;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int t;
    cin >> N >> M;
    rep(i, 1, N + 1) d.pb(i);
    rep(i, 0, M) {
        cin >> t;
        lc.pb(t);
    }
    
    for(auto i : lc)
        cnt += solve(i);
    cout << cnt;
}