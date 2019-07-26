#include <cstdio>

int main() {
    int T; scanf("%d", &T);
    int h, w, n, floor, room; 
    while(T--) { // w is useless.
        scanf("%d%d%d", &h, &w, &n);
        room = n / h; floor = n % h;
        if(floor > 0) ++room;
        else floor = h; // only for n == 1
        printf("%d%02d\n", floor, room);
    }
}