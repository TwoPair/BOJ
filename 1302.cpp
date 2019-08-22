#include <bits/stdc++.h>
using namespace std;
typedef map<string, int> msi;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    msi m;
    string s;
    int n, mx = 0;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(m.count(s) == 0) m.insert({s,1});
        else ++m.find(s)->second;
    }
    
    for(msi::iterator i = m.begin(); i != m.end(); ++i)
        if(i->second > mx) {
            s = i->first;
            mx = i->second;
        }
    
    cout << s;
}