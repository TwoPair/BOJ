#include <cstdio>
#include <cstring>

char s[101];

int main() {
    scanf("%s", s);
    printf("CHICKENS");
    
    int len = strlen(s);
    for(int i = 8; i < len; ++i) printf("%c", s[i] ^ 22);
}