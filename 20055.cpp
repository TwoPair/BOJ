#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int n, n2, k, broken = 0, step = 0;
    cin >> n >> k;
    n2 = n * 2;

    deque<int> conv(n2), robot;
    for (int i = 0; i < n2; i++) cin >> conv[i];

    // [0]: robot load
    // [N-1]: robot unload
    while (broken < k) {
        /* step increased */
        step++;

        /* 1. rotate conv & robot */
        conv.push_front(conv.back());
        conv.pop_back();

        for (auto it = robot.begin(); it != robot.end(); it++)
            *it = (*it + 1) % n2;

        // if a robot reaches the n-1 location, unload it.
        if (!robot.empty()) {
            auto it = find(robot.begin(), robot.end(), n - 1);
            if (it != robot.end())
                robot.erase(it);
        }


        /* 2. robot move */
        for (auto it = robot.begin(); it != robot.end(); it++) {
            int front_loc = (*it + 1) % n2;
            auto front = (it != robot.begin() ? it - 1 : robot.end() - 1);
            if (*front != front_loc && conv[front_loc] > 0) {
                *it = front_loc;
                if (--conv[front_loc] == 0)
                    broken++;
            }
        }

        // if a robot reaches the n-1 location, unload it.
        if (!robot.empty()) {
            auto it = find(robot.begin(), robot.end(), n - 1);
            if (it != robot.end())
                robot.erase(it);
        }
        

        /* 3. robot loading */
        if (conv[0] > 0 && find(robot.begin(), robot.end(), 0) == robot.end()) {
            robot.push_back(0);
            if (--conv[0] == 0)
                broken++;
        }
    }

    cout << step;
}
