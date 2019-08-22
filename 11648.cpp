#include <cstdio>

int step, n;

int parseMul(int n) {
    int ret = 1;
    while(n != 0) {
        ret *= (n%10);
        n /= 10;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    while(n >= 10) {
        n = parseMul(n);
        ++step;
    }
    printf("%d", step);
}