#include <cstdio>

int a, b, c;
int solve() {
    if(b >= c) return -1;
    return a / (c - b) + 1;
}

int main() {
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", solve());
}