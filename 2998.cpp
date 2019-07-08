#include <bits/stdc++.h>
using namespace std;

int main() {
    string bin, ans;
    cin >> bin;
    while(bin.size() % 3 != 0) bin = '0' + bin;
    for(int i = bin.size() - 3; i >= 0; i -= 3)
        ans += ((bin[i] - '0') * 4 + (bin[i + 1] - '0') * 2 + (bin[i + 2] - '0') + '0');
    reverse(ans.begin(), ans.end());
    cout << ans;
}