#include <cstdio>
#include <set>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;++i)

int table[5][5];
bool call[5][5];
set<int> s; // 그어질 수 있는 빙고 줄에 번호를 매겨 사용한다! for excepting to count same lines

void paint(int n) {
    rep(i,0,5) rep(j,0,5)
        if(table[i][j] == n) {
            call[i][j] = true; break;
        }
}

void diagonal() {
    bool found = true;
    
    if(s.count(10) == 0) {
    	rep(i,0,5) if(!call[i][i]) { found = false; break; }
    	if(found) s.insert(10);
    }
    found = true;
    if(s.count(11) == 0) {
    	rep(i,0,5) if(!call[4-i][i]) { found = false; break; }
    	if(found) s.insert(11);
    }
}

void line() {
    bool found = true;
    
    // row
    rep(i,0,5)
    	if(s.count(i) == 0) {
	        rep(j,0,5) if(!call[i][j]) { found = false; break; }
	        if(found) s.insert(i);
	        found = true;
	    }
    // col
    rep(i,0,5)
    	if(s.count(i+5) == 0) {
		    rep(j,0,5) if(!call[j][i]) { found = false; break; }
		    if(found) s.insert(i + 5);
		    found = true;
		}
}

void check() {
    diagonal(); line();
}

int main() {
    rep(i,0,5) rep(j,0,5) call[i][j] = false;
    
    int n, cnt = 0;
    rep(i,0,5) rep(j,0,5) scanf("%d", &table[i][j]);
    rep(i,0,25) {
        scanf("%d", &n);
        paint(n);
        if(i > 6) {
            check();
            if(s.size() >= 3) { printf("%d", i+1); break; }
        }
    }
}