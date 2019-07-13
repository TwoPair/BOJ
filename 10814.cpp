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
typedef pair<int,string> PIS;
// head

bool cmp(const PIS &a, const PIS &b) {
    return a.fi < b.fi;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    PIS p[100002];
    int n, age;
    string name;
    cin >> n;
    rep(i, 0, n) {
        cin >> age >> name;
        p[i] = mp(age, name);
    }
    stable_sort(p, p + n, cmp);
    rep(i, 0, n) cout << p[i].fi << ' ' << p[i].se << '\n';
}