#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int N, M;
vector<vector<int>> edges;
vector<bool> visited;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    /**
     * Find parent index of x.
     */
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    /**
     * Union operation using union-by-rank.
     */
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

    friend int countRoots(DisjointSet&);
};

int countRoots(DisjointSet& ds) {
    set<int> root;
    for (auto p: ds.parent)
        root.insert(ds.find(p));
    return (int)root.size() - 1;
}

int main() {
    fastio
    cin >> N >> M;

    DisjointSet ds(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ds.unionSets(a, b);
    }

    cout << countRoots(ds);
}
