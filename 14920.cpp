#include <cstdio>

int idx = 1, n;

int main() {
    scanf("%d", &n);
    while(n != 1) {
        if(n&1) n = 3*n + 1;
        else n >>= 1;
        ++idx;
    }
    printf("%d", idx);
}