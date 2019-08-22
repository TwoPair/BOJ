#include <bits/stdc++.h>
using namespace std;

int n[10];

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    bool related = true;
    int ans = 0;
    string s; cin >> s;
    for(int i = 0; i < s.size(); ++i) {
    	int c = s[i] - '0';
        n[c]++;
        if(c != 2 && c != 0 && c != 1 && c != 8) {
            related = false;
            break;
        }
    }
    
    if(related) {
        ans = 1;
        if(n[2] > 0 && n[0] > 0 && n[1] > 0 && n[8] > 0) {
            ans = 2;
            
            int cnt = n[2];
            if(n[0] == cnt && n[1] == cnt && n[8] == cnt)
                ans = 8;
        }
    }
    
    cout << ans;
}