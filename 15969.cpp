#include <bits/stdc++.h>
using namespace std;

int num, n[1001];

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> num;
    for(int i = 0; i < num; ++i) cin >> n[i];
    
    auto p = minmax_element(n, n + num);
    cout << *p.second - *p.first;
}