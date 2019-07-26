#include <cstdio>

int ans;
int parseSum(int n) {
    int sum = n;
    while(n != 0) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int main() {
    int n, ps; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        ps = parseSum(i);
        if(ps == n) {
            ans = i; break;
        }
    }
    printf("%d", ans);
}