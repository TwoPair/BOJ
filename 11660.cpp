#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int N, M;
vector<int> accum_line;
vector<vector<int>> dp;

int main() {
    fastio
    cin >> N >> M;

    accum_line.resize(N + 1);
    dp.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        fill(accum_line.begin() + 1, accum_line.end(), 0);
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            accum_line[j] = accum_line[j - 1] + x;
            dp[i][j] = dp[i - 1][j] + accum_line[j];
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
    }
}