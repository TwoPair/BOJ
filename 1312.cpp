#include <cstdio>

int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    while(n--) {
        a %= b;
        a *= 10;
    }
    printf("%d", a / b);
}