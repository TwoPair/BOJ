#include <cstdio>

char n[102];
int l, sc;

int main() {
    scanf("%d %s", &l, n);
    
    for(int i = 0; i < l; ++i) sc += (n[i] - '@');
    printf("%d", sc);
}