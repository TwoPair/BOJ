#include <cstdio>

int n, r;

int main() {
    while(true) {
        int ls = 0;
        scanf("%d", &n);
        if(!n) break;
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &r);
            if(r) ++ls;
        }
        
        printf("Mary won %d times and John won %d times\n", n - ls, ls);
    }
}