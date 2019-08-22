#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;++i)
#define fi first
#define se second
#define MAX 987654321
typedef pair<int, int> node;

int V, E, K; // K -> start vertex's index
vector<vector<node> > adj;

struct cmp {
    bool operator() (const node &x, const node &y) const {
        return x.se > y.se;
    }
};

void dijkstra() {
    // init
    int u, d, v, w;
    priority_queue<node, vector<node>, cmp> pq;
    vector<int> dist(V + 1, MAX); dist[K] = 0;
    pq.push({K, 0});
    rep(i,1,V+1)
        if(i != K) pq.push({i, MAX});
    
    while(!pq.empty()) {
        u = pq.top().fi;
        d = pq.top().se;
        pq.pop();
        if(d > dist[u]) continue; // 최소의 간선치로 정해짐
        
        rep(i,0,adj[u].size()) {
            v = adj[u][i].fi; w = adj[u][i].se;
            if(dist[v] > dist[u] + w) { // Triangle Inequality!
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    } // end of while
    
    // Finally, print answer.
    rep(i,1,V+1) printf(dist[i] == MAX ? "INF\n" : "%d\n", dist[i]);
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v, w;
    cin >> V >> E >> K;
    adj.resize(V + 1);
    rep(i,0,E) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra();
}