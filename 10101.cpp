#include <bits/stdc++.h>
using namespace std;

string ans;
int ang[3], sum;

int main() {
    for(int i = 0; i < 3; ++i) { cin >> ang[i]; sum += ang[i]; }
    
    if(sum != 180) ans = "Error";
    else {
        if(ang[0] == 60 && ang[1] == 60 && ang[2] == 60) ans = "Equilateral";
        else if(ang[0] != ang[1] && ang[0] != ang[2] && ang[1] != ang[2]) ans = "Scalene";
        else ans = "Isosceles";
    }
    
    cout << ans;
}