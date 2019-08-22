#include <cstdio>

int main() {
    double mx = 0;
    int a,b,c,d,m,t;
    scanf("%d%d%d%d", &a,&b,&c,&d);
    
    for(int i=0;i<4;++i) {
        double k = (double)a/c+(double)b/d;
        if(k > mx) {
            mx = k;
            m = i;
        }
        t=a; a=c; c=d; d=b; b=t;
    }
    printf("%d", m);
}