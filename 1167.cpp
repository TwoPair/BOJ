// https://blog.myungwoo.kr/112

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int V;
vector<int> dist;
vector<vector<pair<int, int>>> tree;

int bfs(int start) {
    queue<int> q;
    fill(dist.begin(), dist.end(), 2e9);

    dist[start] = 0; q.push(start);
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = (int)tree[front].size(); i--;) {
            int nxt = tree[front][i].first, d = tree[front][i].second;
            if (dist[nxt] < 2e9)    // means "visited"
                continue;
            dist[nxt] = dist[front] + d;
            q.push(nxt);
        }
    }

    return max_element(dist.begin() + 1, dist.end()) - dist.begin();
}

int main() {
    cin >> V;
    tree.resize(V + 1);
    dist.resize(V + 1);

    for (int i = 0; i < V; ++i) {
        int from, to, _w;
        cin >> from;

        while (cin >> to && to != -1) {
            cin >> _w;
            tree[from].push_back({to, _w});
        }
    }

    int x = 1;
    int y = bfs(x);
    int z = bfs(y);
    cout << dist[z];
}