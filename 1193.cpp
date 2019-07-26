#include <cstdio>

int main() {
    int n, sum = 0, i = 1; scanf("%d", &n);
    while(true) {
        if(n <= sum + i) {
            int a = n-sum;
            if(i&1 == 1) printf("%d/%d", i+1-a, a);
            else printf("%d/%d", a, i+1-a);
            break;
        }
        sum += i++;
    }
}