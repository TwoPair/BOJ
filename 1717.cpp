#include <cstdio>
#include <algorithm>
using std::fill;

int ds[1000002];

int Find(int x) {
    if(ds[x] < 0) return x;
    else {
        ds[x] = Find(ds[x]);
        return ds[x];
    }
}

void Union(int rt1, int rt2) {
    if(rt1 != rt2) {
        if(ds[rt1] < ds[rt2]) ds[rt2] = rt1;
        else ds[rt1] = rt2;
    }
}

int main() {
    int op, a, b;
    int n, m; scanf("%d%d", &n, &m);
    fill(ds, ds+n+1, -1);
    
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &op, &a, &b);
        if(op == 0) Union(Find(a), Find(b));
        else printf("%s\n", Find(a) == Find(b) ? "YES" : "NO");
    }
}