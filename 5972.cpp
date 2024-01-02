#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF 1e9
#define MAX 50001
using namespace std;

vector<pair<int, int>> node[MAX];
vector<int> dist;

// dijkstra using heap
void dijkstra(int start) {
    // first:  cost
    // second: node
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < node[here].size(); ++i) {
            int via_cost = cost + node[here][i].second;
            int next_node = node[here][i].first;

            if (via_cost < dist[next_node]) {
                dist[next_node] = via_cost;
                pq.push(make_pair(-via_cost, next_node));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dist.assign(n + 1, INF);

    while (m--) {
        int i, j, cost;
        cin >> i >> j >> cost;
        node[i].push_back(make_pair(j, cost));
        node[j].push_back(make_pair(i, cost));
    }

    dijkstra(1);

    cout << dist[n];
}