#include <iostream>
#include <queue>
#include <utility>
using namespace std;

void rotate_1(queue<pair<int, int>> &q) {
    // rotate 1
    q.push(q.front());
    q.pop();
}

int solve() {
    int count = 0;
    int n, m, tmp, target_importancy;
    cin >> n >> m;

    queue<pair<int, int>> q;
    priority_queue<int> pq;

    // `first`:     importancy
    // `second`:    target set on 1
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (i == m) {
            q.push({tmp, 1});
            target_importancy = tmp;
        } else {
            q.push({tmp, 0});
        }

        pq.push(tmp);
    }

    while (true) {
        if (pq.top() == q.front().first) {
            count++;
            if (q.front().second == 1)
                return count;

            q.pop();
            pq.pop();
        } else {
            rotate_1(q);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--)
        cout << solve() << '\n';
}