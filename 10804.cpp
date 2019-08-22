#include <bits/stdc++.h>
using namespace std;

int n[22];

int main() {
    int a, b;
    for(int i = 1; i <= 20; ++i) n[i] = i;
    for(int i = 0; i < 10; ++i) {
        scanf("%d%d", &a, &b);
        reverse(n+a, n+b+1);
    }
    for(int i = 1; i <= 20; ++i) printf("%d ", n[i]);
}