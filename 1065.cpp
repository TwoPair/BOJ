#include <cstdio>

bool hansu(int n) {
    if(n < 10) return true;
    int gap = n%10 - n/10%10, before = n/10%10;
    n /= 100;
    
    while(n != 0) {
        if(before - n%10 != gap) return false;
        n /= 10;
    }
    
    return true;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        if(hansu(i)) ++cnt;
    printf("%d", cnt);
}