#include <bits/stdc++.h>

int rope[100002];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", rope + i);
    
    std::sort(rope, rope + n, std::greater<int>());
    
    int max = rope[0];
    for(int i = 1; i < n; ++i)
        if(max < rope[i] * (i + 1))
            max = rope[i] * (i + 1);
    
    printf("%d", max);
}