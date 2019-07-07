#include <cstdio>
#define rep(i,a,n) for (int i=a;i<n;++i)

int main() {
    int n, blank, mid = 1;
    scanf("%d", &n);
    blank = n - 1;
    
    rep(i, 0, blank) printf(" ");
    printf("*\n");
    --blank;
    
    rep(i, 0, n-1) {
        rep(j, 0, blank) printf(" ");
        printf("*");
        rep(j, 0, mid) printf(" ");
        printf("*\n");
        --blank; mid += 2;
    }
}