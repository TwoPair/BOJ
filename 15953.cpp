#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;++i)
using namespace std;

int one[7] = {0,500,300,200,50,30,10},
    two[6] = {0,512,256,128,64,32},
    l1[8] = {-1,0,1,3,6,10,15,21},
    l2[7] = {-1,0,1,3,7,15,31};

int main() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, a, b;
    cin >> q;
    
    while(q--) {
        int res=0;
        cin >> a >> b;
        rep(i,1,8) if(l1[i-1] < a && a <= l1[i]) {res += one[i-1]; break;}
        rep(i,1,7) if(l2[i-1] < b && b <= l2[i]) {res += two[i-1]; break;}
        
        cout << res * 10000 << '\n';
    }
}