#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;++i)
#define se second
typedef pair<int,int> PII;
// head

priority_queue<PII > pq; // MAX heap

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int n, x;
    cin >> n;
    rep(i,0,n) {
        cin >> x;
        if(x != 0) pq.push({-abs(x), -x});
        else {
            if(pq.empty()) cout << 0 << '\n';
            else { cout << -pq.top().se << '\n'; pq.pop(); }
        }
    }
}