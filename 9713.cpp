#include <cstdio>

int main() {
    int q, n;
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d", &n);
        n = (n + 1) / 2;
        printf("%d\n", n * n);
    }
}