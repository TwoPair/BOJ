#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;++i)

char map[11][13];
bool row[10], col[10];

int main() {
    int r, c, mv = 101;
    scanf("%d%d", &r, &c); 
    rep(i,0,10) {
    	getchar();
    	rep(j,0,10) scanf("%c", &map[i][j]);
    }
    
    rep(i,0,10) { row[i] = true; col[i] = true; }
    rep(i,0,10) rep(j,0,10)
        if(map[i][j] == 'o') { row[i] = false; col[j] = false; }
    
    rep(i,0,10) rep(j,0,10)
        if(row[i] && col[j]) {
            int gap = abs(i+1 - r) + abs(j+1 - c);
            if(gap < mv) mv = gap;
        }
    
    printf("%d", mv);
}