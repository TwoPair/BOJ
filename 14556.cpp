#include <iostream>
using namespace std;

// 동적 계획법!!
int main() {
    int n;
    long long r = 1;
    cin >> n;

    for (int i = 1; i <= n; i++)
        r = (r * (2 * i - 1)) % (int(1e9) + 9); // 홀수 곱
    cout << r;
}