#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    char c[28];
    int T;
    cin >> T;
    
    while(T--) {
    	getchar();
        getline(cin, s);
        cin >> c;
        for(char &i : s) {
            if(i != ' ') cout << c[i - 'A'];
            else cout << ' ';
        }
        cout << '\n';
    }
}