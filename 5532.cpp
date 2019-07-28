#include <cstdio>
#define max(a,b) (a>b?a:b)
#define rmd(a,b) (a%b?1:0)

int main() {
    int l,a,b,c,d,mt,ko;
    scanf("%d%d%d%d%d", &l,&a,&b,&c,&d);
    ko = a/c + rmd(a,c); mt = b/d + rmd(b,d);
    printf("%d", l-max(ko,mt));
}