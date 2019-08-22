#include <bits/stdc++.h>
using namespace std;

int n;
string str;
set<string> s;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        s.insert(str);
    }
    
    cout << (s.count("anj") == 1 ? "뭐야;" : "뭐야?");
}