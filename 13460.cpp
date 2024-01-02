#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOVE_CHECK_RESET(first, second, func, num) \
    hole_##first = first.func(); \
    hole_##second = second.func(); \
    \
    if (hole_in(hole_red, hole_blue)) { \
    result = min(result, step); \
    reset(before_##first, first.getP(), first.getCh()); \
    reset(before_##second, second.getP(), second.getCh()); \
    return; \
    } else if (!hole_blue && (before_##first != first.getP() || before_##second != second.getP())) { \
    dfs(step + 1, num); \
    } \
    reset(before_##first, first.getP(), first.getCh()); \
    reset(before_##second, second.getP(), second.getCh());

#define RED_FIRST(func, num) MOVE_CHECK_RESET(red, blue, func, num)
#define BLUE_FIRST(func, num) MOVE_CHECK_RESET(blue, red, func, num)


/* Class */
class Point {
public:
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
};

class Ball {
    char ch;
    Point p;

    bool move(int direction);
public:
    Ball() {}
    Ball(char ch, const Point &p);

    bool operator==(const Ball &rhs) const;
    bool operator!=(const Ball &rhs) const;

    Point &getP();

    char getCh() const;

    bool up();
    bool down();
    bool left();
    bool right();
};

/* Global variable */
int N, M, result = 11;
vector<vector<char>> board;
Ball red, blue;
Point hole;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

/* Function */
int solve();
void dfs(int step, int before_direction);
inline bool hole_in(bool r, bool b);
void reset(const Point& before, Point& after, char ch);

void print_board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "\n";
}

/* ----------- MAIN ----------- */
int main() {
    cin >> N >> M;

    board.resize(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                red = Ball('R', {i, j});
            else if (board[i][j] == 'B')
                blue = Ball('B', {i, j});
            else if (board[i][j] == 'O')
                hole = Point(i, j);
        }

    cout << solve();
}
/* ---------------------------- */

/**
 * The final step saves in the `result` variable.
 * @return `result` value
 */
int solve() {
    dfs(1, 4);
    return (result <= 10 ? result : -1);
}

void dfs(int step, int before_direction) {
    if (step > 10) return;

//    cout << step << ")\n";
//    print_board();

    Point before_red = red.getP();
    Point before_blue = blue.getP();

    bool hole_red = false, hole_blue = false;

    // up
    if (before_direction != 0) {
        if (before_red.x <= before_blue.x) {
            RED_FIRST(up, 0)
        } else {
            BLUE_FIRST(up, 0)
        }
    }
    // down
    if (before_direction != 1) {
        if (before_red.x >= before_blue.x) {
            RED_FIRST(down, 1)
        } else {
            BLUE_FIRST(down, 1)
        }
    }
    // left
    if (before_direction != 2) {
        if (before_red.y <= before_blue.y) {
            RED_FIRST(left, 2)
        } else {
            BLUE_FIRST(left, 2)
        }
    }
    // right
    if (before_direction != 3) {
        if (before_red.y >= before_blue.y) {
            RED_FIRST(right, 3)
        } else {
            BLUE_FIRST(right, 3)
        }
    }
}

inline bool hole_in(bool r, bool b) {
    return r && !b;
}

void reset(const Point& before, Point& after, char ch) {
    board[after.x][after.y] = '.';
    board[before.x][before.y] = ch;

    after = Point(before);
}


Ball::Ball(char ch, const Point &p) : ch(ch), p(p) {}

// 공의 움직임은 서로 방해되지 않도록 이동하려는 방향의 벽에서 가까운 공부터 이동하도록
// 구현하는 것을 dfs() 함수에서 guarantee한다.
/**
 * Move a ball with given direction.
 * If the ball does not move, board would not be updated.
 * @param direction
 * @return if a ball meets a hole
 */
bool Ball::move(int direction) {
    Point before(p);
    Point after(p);

    while (true) {
        int nx = after.x + dx[direction];
        int ny = after.y + dy[direction];

        if (board[nx][ny] == 'O') {
            board[p.x][p.y] = '.';
            p = {0, 0};
            return true;
        }

        if (board[nx][ny] != '.')
            break;

        after.x = nx;
        after.y = ny;
    }

    // board update
    if (before != after) {
        board[before.x][before.y] = '.';
        board[after.x][after.y] = ch;

        p = after;
    }

    return false;
}

bool Ball::up() {
    return move(0);
}

bool Ball::down() {
    return move(1);
}

bool Ball::left() {
    return move(2);
}

bool Ball::right() {
    return move(3);
}

bool Ball::operator==(const Ball &rhs) const {
    return p == rhs.p;
}

bool Ball::operator!=(const Ball &rhs) const {
    return !(rhs == *this);
}

Point &Ball::getP() {
    return p;
}


char Ball::getCh() const {
    return ch;
}


bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}