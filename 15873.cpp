#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    
    if(s.size() == 4) cout << 20;
    else if(s.size() == 2) cout << s[0] + s[1] - 2 * '0';
    else {
        if(s[1] == '0') cout << 10 + s[2] - '0';
        else cout << 10 + s[0] - '0';
    }
}