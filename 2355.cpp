#include <cstdio>
#include <algorithm>

long long a, b, ans;

int main() {
    int tmp;
    scanf("%lld%lld", &a, &b);
    if(a > b) std::swap(a, b);
    printf("%lld", (b-a+1) * (a+b) / 2);
}