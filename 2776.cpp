#include <cstdio>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;++i)

int main() {
    int T, n, m, tmp;
    scanf("%d", &T);
    
    while(T--) {
        int a[1000001];
        scanf("%d", &n);
        rep(i,0,n) { scanf("%d", &tmp); a[i] = tmp; }
        std::sort(a, a+n);
        scanf("%d", &m);
        rep(i,0,m) { 
            scanf("%d", &tmp); 
            std::binary_search(a, a+n, tmp) ? puts("1") : puts("0");
        }
    }
}