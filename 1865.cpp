// Belman-ford algorithm: O(|V||E|)
// 문제 정리: https://www.acmicpc.net/board/view/72995 ⭐️⭐️⭐️
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

/**
 * 도달할 수 없는 정점도 있다고 생각하고 진행해야 한다.
 * 만약 아래와 같이 음수 사이클의 유무만 체크하는 것이 아니라 "최소값"도 알고 싶다면,
 * 나의 다른 방식으로 푼 알고리즘을 쓰는 것이 좋을 것이다.
 * https://www.acmicpc.net/source/70343335
 */

struct Edge {
    int source, destiantion, weight;
};

class BellmanFord {
private:
    int numNodes;
    vector<Edge> edges;
    vector<int> distance;

public:
    BellmanFord(int n) : numNodes(n) {
        // 0 init for detecting negative cycle even it locates anywhere.
        distance.resize(numNodes + 1, 0);
    }

    void addEdge(int s, int d, int w) {
        edges.push_back({s, d, w});
    }

    void addDoubleEdge(int s, int d, int w) {
        addEdge(s, d, w);
        addEdge(d, s, w);
    }

    bool relaxEdges() {
        bool hasNegativeCycle = false;

        for (int i = 0; i < numNodes; ++i) {    // (N - 1) repeat + 1 check routine
            for (const Edge& edge : edges) {
                if (distance[edge.source] != numeric_limits<int>::max() &&
                    distance[edge.source] + edge.weight < distance[edge.destiantion]) {
                    distance[edge.destiantion] = distance[edge.source] + edge.weight;
                    if (i == numNodes - 1)
                        hasNegativeCycle = true;
                }
            }
        }

        return hasNegativeCycle;
    }

    void solve() {
        if (relaxEdges())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
};

int N, M, W;

int main() {
    fastio
    int TC, s, e, w;
    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;

        BellmanFord graph(N);

        for (int i = 0; i < M; ++i) {
            cin >> s >> e >> w;
            graph.addDoubleEdge(s, e, w);
        }

        for (int i = 0; i < W; ++i) {
            cin >> s >> e >> w;
            graph.addEdge(s, e, -w);
        }

        graph.solve();
    }
}