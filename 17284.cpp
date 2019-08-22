#include <cstdio>

int bt[4];

int main() {
    int n;
    while(~scanf("%d", &n)) bt[n]++;
    
    printf("%d", 5000 - 500*bt[1] - 800*bt[2] - 1000*bt[3]);
}