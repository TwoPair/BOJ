#include <bits/stdc++.h>
using namespace std;

int main() {
    int num[3]; char seq[3];
    for(int i = 0; i < 3; ++i) cin >> num[i];
    for(int i = 0; i < 3; ++i) cin >> seq[i];
    sort(num, num + 3);
    for(int i = 0; i < 3; ++i) cout << num[seq[i] - 'A'] << ' ';
}