#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 50

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N, L, R;
vector<vector<int>> population;

class Point {
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void set_value(int val) {
        population[x][y] = val;
    }
};

class Group {
    vector<Point> uni;
    int sum;
public:
    Group() {
        sum = 0;
    }

    bool empty() {
        return uni.empty();
    }

    void add(int x, int y) {
        uni.push_back(Point(x, y));
        sum += population[x][y];
    }

    void clear() {
        uni.clear();
        sum = 0;
    }

    void move_people() {
        int avg = sum / uni.size();
        for (auto &p : uni)
            p.set_value(avg);
    }
};

void dfs(int x, int y, vector<vector<int>>& open, vector<vector<bool>>& visited, Group& group) {
    visited[x][y] = true;
    group.add(x, y);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // not out of bound & not visited '1'
        if (nx >= 0 && nx < N &&
            ny >= 0 && ny < N &&
            open[nx][ny] == 1 &&
            !visited[nx][ny]) {
            int gap = abs(population[x][y] - population[nx][ny]);
            if (gap >= L && gap <= R)
                dfs(nx, ny, open, visited, group);
        }
    }
}

bool solve(vector<vector<int>>& open) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    Group group;
    bool movement_occurance = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (open[i][j] == 1 && !visited[i][j]) {
                // 새로운 그룹 발견해서 DFS로 그룹의 모든 요소 탐색
                dfs(i, j, open, visited, group);
                // group에 다 모아왔을 것이니 이를 통해 값 갱신 후 초기화
                movement_occurance = movement_occurance || !group.empty();
                group.move_people();
                group.clear();
            }
        }
    }

    return movement_occurance;
}

void make_open(vector<vector<int>>& open) {
    int nx, ny, gap;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            nx = i + 1; ny = j;
            if (nx < N) {
                gap = abs(population[i][j] - population[nx][ny]);
                if (gap >= L && gap <= R) {
                    open[i][j] = 1;
                    open[nx][ny] = 1;
                }
            }

            nx = i; ny = j + 1;
            if (ny < N) {
                gap = abs(population[i][j] - population[nx][ny]);
                if (gap >= L && gap <= R) {
                    open[i][j] = 1;
                    open[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    int day = 0;

    cin >> N >> L >> R;

    population.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> population[i][j];
        }
    }

    while (true) {
        vector<vector<int>> open(N, vector<int>(N, 0));
        make_open(open);
        if (!solve(open))
            break;
        day++;
    }

    cout << day;
}