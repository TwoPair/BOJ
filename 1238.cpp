#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 987654321

struct Edge {
    int destination, weight;
};

int N, M, X;
vector<vector<Edge>> edges;
vector<int> dist[2];

void dijkstra(int start, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > distance[current]) continue;

        for (auto& edge: edges[current]) {
            int neighbor = edge.destination;
            int weight = edge.weight;

            if (distance[current] + weight < distance[neighbor]) {
                distance[neighbor] = distance[current] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }
}

int solve() {
    // step 1) x -> other  : O(n * logn)
    vector<int> distance(N + 1, INF);
    dijkstra(X, distance);
    dist[0] = distance;

    // step 2) other -> x  : O(n * n * logn)
    for (int i = 1; i <= N; ++i) {
        if (i != X) {
            fill(distance.begin() + 1, distance.end(), INF);
            dijkstra(i, distance);
            dist[1][i] = distance[X];
        } else {
            dist[1][i] = 0;
        }
    }

    // step 3) who's the slowest one
    int slow = 0;
    for (int i = 1; i <= N; ++i)
        slow = max(slow, dist[0][i] + dist[1][i]);

    return slow;
}

int main() {
    fastio
    cin >> N >> M >> X;
    edges.resize(N + 1);
    dist[0].resize(N + 1, INF); // x -> other
    dist[1].resize(N + 1, INF); // other -> x
    for (int i = 0; i < M; ++i) {
        int s, e, t;
        cin >> s >> e >> t;
        edges[s].push_back({e, t});
    }

    cout << solve();
}