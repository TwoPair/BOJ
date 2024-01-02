#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

/** Back-tracking **/
/*
 * 다른 사람 아이디어:
 * 먼저 알파벳 겹치는 건 int 변수 하나에 비트 연산으로 쌓아서 비교했다.
 * board와 같은 크기의 배열을 만들어서 그곳에는 위의 비트 연산된 값을 각 step마다 저장했다.
 * 비트 연산 매우 빠름, 동시에 visited 여부를 검사할 수 있음(0이면 방문 안한거).
 */

int R, C, result = 0;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, vector<int>& passed) {
    visited[x][y] = true;
    passed[board[x][y] - 'A'] = 1;

    bool nowhere_to_go = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R &&
            ny >= 0 && ny < C &&
            !visited[nx][ny] &&
            passed[board[nx][ny] - 'A'] != 1) {
            dfs(nx, ny, board, visited, passed);
            visited[nx][ny] = false;
            passed[board[nx][ny] - 'A'] = 0;
            nowhere_to_go = false;
        }
    }

    if (nowhere_to_go)
        result = max(result, accumulate(passed.begin(), passed.end(), 0));
}

int main() {
    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<int> passed(26, 0);

    dfs(0, 0, board, visited, passed);
    cout << result;
}