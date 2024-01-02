#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int N;
vector<int> v;
vector<int> sum;

void findLIS_bigSum() {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] > v[j] && sum[i] < sum[j] + v[i])
                sum[i] = sum[j] + v[i];
}

int findBiggest() {
    return *max_element(sum.begin(), sum.end());
}

int main() {
    fastio
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sum = v;

    findLIS_bigSum();
    cout << findBiggest();
}
