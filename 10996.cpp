#include <cstdio>
#define rep(i,a,n) for(int i=a;i<n;++i)

char s1[102], s2[102];

int main() {
    int n; scanf("%d", &n);
    rep(i,0,n) {
        if(i&1) { s1[i] = ' '; s2[i] = '*'; }
        else { s1[i] = '*'; s2[i] = ' '; }
    }
    
    if(n == 1) printf("*");
    else 
        rep(i,0,n) printf("%s\n%s\n", s1, s2);
}