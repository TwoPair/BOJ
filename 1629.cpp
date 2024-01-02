#include <iostream>
using namespace std;
typedef long long ll;

int mod;

// 반복되는 것을 분할해서 작은 작업으로 해결한 뒤 합치는 것을 "분할 정복"이라고 함.
ll recur(int n, int m) {
    if (m > 1) {
        ll result = recur(n, m / 2);
        if (m % 2)
            return (((result * result) % mod) * n) % mod;
        else
            return (result * result) % mod;
    } else {
        return n % mod;
    }
}

int main() {
    int n, m;
    cin >> n >> m >> mod;

    cout << recur(n, m);
}