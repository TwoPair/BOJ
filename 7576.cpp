#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, M, day = 0, l = 0;
vector<vector<int>> box;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(queue<pair<int, int>>& tomatoes, queue<pair<int, int>>& next_gen) {
    while (!tomatoes.empty()) {
        auto tomato = tomatoes.front();
        tomatoes.pop();

        int x = tomato.first;
        int y = tomato.second;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N &&
                ny >= 0 && ny < M &&
                box[nx][ny] == 0) {
                box[nx][ny] = 1;
                l--;
                next_gen.push({nx, ny});
            }
        }

    }
}

void solve() {
    queue<pair<int, int>> new_tomato, next_gen;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (box[i][j] == 1)
                new_tomato.push({i, j});

    while (true) {
        if (!new_tomato.empty() && l > 0) {
            dfs(new_tomato, next_gen);
            swap(new_tomato, next_gen);
            day++;
        } else {
            break;
        }
    }
}

int main() {
    int tomato;
    cin >> M >> N;
    box.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tomato;
            box[i][j] = tomato;
            if (tomato == 0)
                l++;
        }
    }

    solve();
    cout << (l == 0 ? day : -1);
}