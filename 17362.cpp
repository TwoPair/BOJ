#include <cstdio>

int r[] = {2,1,2,3,4,5,4,3};

int main() {
    int n; scanf("%d", &n);
    printf("%d", r[n%8]);
}