#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

class Sort {
public:
    virtual void sort() = 0;
    virtual void print(string delimiter = " ") = 0;
};

/**
 * 위상 정렬. DAG(Directed Acyclic Graph)에만 적용 가능.
 * 순서가 정해져있는 작업을 차례로 수행해야 할 때 그 순서를 결정해주기 위해 사용하는 알고리즘.
 * 답이 여러개가 될 수 있다는 특징.
 * O(|V| + |E|)
 * 
 * 사용된 문제 -> 2252, 1005
 */
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

#endif // SORT_H
