// Floyd algorithm: O(n^3)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 987654321

int n, m;
vector<vector<int>> dist;

void floyd() {
    for (int k = 0; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << (dist[i][j] != INF ? dist[i][j] : 0) << " ";
        cout << "\n";
    }
}

int main() {
    fastio
    cin >> n >> m;

    dist.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    while (m--) {
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }
    
    floyd();
    print();
}