#include <cstdio>

unsigned int n;

bool squareOfTwo() {
    int onlyOne = 0;
    while(n != 0) {
        if((n & 1) == 1) ++onlyOne;
        n >>= 1;
        if(onlyOne == 2) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    printf("%d", squareOfTwo() ? 1 : 0);
}