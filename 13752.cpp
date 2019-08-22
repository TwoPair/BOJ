#include <cstdio>
int n,t;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        while(t--) printf("=");
        printf("\n");
    }
}