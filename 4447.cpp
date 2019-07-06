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
    int n; string s;
    cin >> n;
    cin.ignore();
    while(n--) {
        int g = 0, b = 0;
        getline(cin, s);
        
        rep(i, 0, sz(s)) {
            if(s[i] == 'g' || s[i] == 'G') ++g;
            else if(s[i] == 'b' || s[i] == 'B') ++b;
        }
        
        cout << s << " is ";
        if(g > b) cout << "GOOD\n";
        else if(g < b) cout << "A BADDY\n";
        else cout << "NEUTRAL\n";
    }
}