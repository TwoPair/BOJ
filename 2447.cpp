#include <bits/stdc++.h>
using namespace std;

int dirt_X[8] = {-1,0,1,-1,1,-1,0,1},
    dirt_Y[8] = {-1,-1,-1,0,0,1,1,1};
vector<vector<char> > s(2190, vector<char>(2190, ' '));

void star(int x, int y, int sz) {
    if(sz == 1) { s[x][y] = '*'; return; }
    
    sz /= 3;
    for(int i = 0; i < 8; ++i)
        star(x+sz*dirt_X[i], y+sz*dirt_Y[i], sz);
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    star(n/2, n/2, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << s[i][j];
        cout << '\n';
    }      
}