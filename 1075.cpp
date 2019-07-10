#include <cstdio>

int main() {
    int n, f, i = 0;
    scanf("%d%d", &n, &f);
    
    n = n / 100 * 100;
    for( ; i < 100; ++i)
    	if((n + i) % f == 0) break;
    
    printf("%02d", i);
}