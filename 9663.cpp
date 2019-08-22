#include <iostream>
using namespace std;

int n, cnt, col[16];

bool promising(int i) {
    for(int k = 1; k < i; ++k)
        if(col[k] == col[i] || abs(col[k] - col[i]) == (i - k))
            return false;
    
    return true;
}

void queen(int i) {
    if(i == n + 1) ++cnt;
    else
        for(int j = 1; j <= n; ++j) {
	col[i] = j;
	if(promising(i)) queen(i + 1);
        }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    queen(1);
    cout << cnt;
}