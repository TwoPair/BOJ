#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int sum = 0, root, R, cnt = 2;
    cin >> root >> R;
    
    while(true) {
        root = root * R/100;
        if(root <= 5) break;
        sum += cnt * root;
        cnt <<= 1;
    }
    
    cout << sum;
}