#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

/**
 * [필독]
 * https://www.acmicpc.net/board/view/30959
 */

// 기존 위상정렬(topology sort)에서 정렬을 할 때 단순히 인접 노드를 빼는게 아니라
// weight 값을 이용해 다음에 접근할 인접 노드를 선택
class TopologySort {
    bool useWeight;
    int N;                  // the number of nodes
    vector<int> inDegree;   // 진입 차수
    vector<vector<int>> graph;
    vector<int> result;
    vector<int> weight;
public:
    explicit TopologySort(int n, bool useWeight) : N(n), useWeight(useWeight) {
        inDegree.resize(N + 1, 0);
        graph.resize(N + 1);
        result.resize(N + 1);
        if (useWeight)
            weight.resize(N + 1);
    }

    tuple<vector<int>&, vector<vector<int>>&> getVectors() {
        return tie(inDegree, graph);
    }

    void setWeight(int idx, int w) {
        weight[idx] = w;
        result[idx] = w;
    }

    void addEdge(int start, int end) {
        graph[start].push_back(end);
        inDegree[end]++;
    }

    void sort() {
        queue<int> q;

        // insert a node which has degree 0 into queue.
        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // visit N nodes for sorting completely.
        for (int i = 1; i <= N; ++i) {
            // a cycle is detected if the queue is empty before visiting all nodes.
            if (q.empty())
                return;

            int x = q.front();
            q.pop();

            if (!useWeight)
                result[i] = x;

            for (int j = 0; j < graph[x].size(); ++j) {
                int next = graph[x][j];
                if (useWeight)
                    result[next] = max(result[next], result[x] + weight[next]);

                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
    }

    int getResult(int idx) {
        return result[idx];
    }

    void print(string delimiter = " ") {
        for (int i = 1; i <= N; ++i) {
            cout << result[i] << delimiter;
        }
    }
};

void solve() {
    int N, K, W;
    cin >> N >> K;

    vector<int> weight(N + 1, 0);
    TopologySort ts(N, true);   // use weight

    for (int i = 1; i <= N; ++i) {
        int weight;
        cin >> weight;
        ts.setWeight(i, weight);
    }

    while (K--) {
        int a, b;
        cin >> a >> b;
        ts.addEdge(a, b);
    }

    cin >> W;

    ts.sort();
    cout << ts.getResult(W) << "\n";
}

int main() {
    fastio
    int T;
    cin >> T;
    while (T--)
        solve();
}
