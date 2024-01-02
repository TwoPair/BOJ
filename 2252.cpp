#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Sort {
public:
    virtual void sort() = 0;
    virtual void print(string delimiter = " ") = 0;
};

class TopologySort : public Sort {
    int N;                  // the number of nodes
    vector<int> inDegree;   // 진입 차수
    vector<vector<int>> graph;
    vector<int> result;
public:
    explicit TopologySort(int n) : N(n) {
        inDegree.resize(N + 1, 0);
        graph.resize(N + 1);
        result.resize(N + 1);
    }

    tuple<vector<int>&, vector<vector<int>>&> getVectors() {
        return tie(inDegree, graph);
    }

    void sort() override {
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
            result[i] = x;
            for (int j = 0; j < graph[x].size(); ++j) {
                int next = graph[x][j];
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
    }

    void print(string delimiter = " ") override {
        for (int i = 1; i <= N; ++i) {
            cout << result[i] << delimiter;
        }
    }
};

int main() {
    int N, M, a, b;
    cin >> N >> M;

    TopologySort ts(N);

    auto [inDegree, graph] = ts.getVectors();

    while (M--) {
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    ts.sort();
    ts.print();
}