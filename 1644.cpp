#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

int N, cnt = 0;
vector<ull> sum;
vector<bool> isPrime;

void sieveOfEratosthenes() {
    isPrime.resize(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void makeSum() {
    sum.push_back(0);
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            sum.push_back(sum.back() + i);
        }
    }
}

// O(N * log N)
void solve() {
    for (int i = 1; i < sum.size(); ++i) {
        if (sum[i] >= N) {
            ull end = sum[i];
            ull start = end - N;

            auto it = lower_bound(sum.begin(), sum.begin() + i, start);
            if (*it == start)
                cnt++;
        }
    }
}

int main() {
    fastio
    cin >> N;

    sieveOfEratosthenes();
    makeSum();
    solve();

    cout << cnt;
}
