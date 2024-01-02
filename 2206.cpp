#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 987654321
using namespace std;

struct Point {
    int x;
    int y;
    int move;
    bool chanceUsed;
};

int N, M, result = INF;
vector<vector<char>> graph;
vector<vector<vector<bool>>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

/** https://www.acmicpc.net/board/view/27386 **/

// 가중치가 없는 최단 경로는 무조건 BFS!!!!
// Because 특정 칸에 처음 도달했을 때까지의 경로의 길이가 다른 경로를 통해 도달한 길이보다 짧다는 보장이 전혀 없기 때문.

//void dfs(int x, int y, int move, bool chanceUsed) {
//    if (x == N && y == M) {
//        result = min(result, move);
//        return;
//    }
//
//    visited[x][y] = true;
//
//    for (int i = 0; i < 4; ++i) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        if (nx > 0 && nx <= N &&
//            ny > 0 && ny <= M &&
//            !visited[nx][ny]) {
//            if (graph[nx][ny] == '0') {
//                dfs(nx, ny, move + 1, chanceUsed);
//                visited[nx][ny] = false;
////                cout << "0: " << nx << " " << ny << "\n";
//            } else {
//                if (!chanceUsed) {
//                    dfs(nx, ny, move + 1, !chanceUsed);
//                    visited[nx][ny] = false;
////                    cout << "1: " << nx << " " << ny << "\n";
//                }
//            }
//        }
//    }
//}

void bfs() {
    queue<Point> q;
    q.push({1, 1, 1, false});

    while (!q.empty()) {
        auto p = q.front();
        int x = p.x;
        int y = p.y;
        int move = p.move;
        bool chanceUsed = p.chanceUsed;
        int chanceIdx = chanceUsed ? 1 : 0;
        q.pop();

        if (x == N && y == M) {
            result = min(result, move);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
                if (graph[nx][ny] == '0') {
                    if (!visited[nx][ny][chanceIdx]) {
                        q.push({nx, ny, move + 1, chanceUsed});
                        visited[nx][ny][chanceIdx] = true;
                    }
                } else {    // '1'
                    if (!chanceUsed) {
                        q.push({nx, ny, move + 1, !chanceUsed});
                    }
                }
            }
        }
    }
}

int main() {
    fastio
    cin >> N >> M;
    graph.resize(N + 1, vector<char>(M + 1, '1'));
    visited.resize(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2, false)));
    // visited 마지막이 크기가 2인 이유)
    // - 벽을 부수는 기회(1회)를 사용해서 이동한건지 아닌지를 구분하기 위한 차원을 설정해준 것이다!!!

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> graph[i][j];

//    dfs(1, 1, 1, false);
    bfs();
    cout << (result == INF ? -1 : result);
}
