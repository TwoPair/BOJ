#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int n, arr[500002];
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    
    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
}