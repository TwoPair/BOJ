#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 100001
using namespace std;

int N, S, result = MAX;
vector<int> v, sum;

// O(N*log N)
void solve() {
    for (int i = 1; i <= N; ++i) {
        if (sum[i] >= S) {
            auto it = upper_bound(sum.begin(), sum.begin() + i, sum[i] - S);
            result = min(result, (int)distance(it, sum.begin() + i) + 1);
        }
    }
}

int main() {
    fastio
    cin >> N >> S;
    v.resize(N + 1);
    sum.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    solve();
    cout << (result == MAX ? 0 : result);
}
