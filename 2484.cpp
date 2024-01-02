#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, rich = 0;

int main() {
    cin >> n;
    while (n--) {
        vector<int> dice(7, 0);
        set<int> s;

        for (int i = 0; i < 4; ++i) {
            int roll; cin >> roll;
            s.insert(roll);
            dice[roll]++;
        }

        auto same = s.size();
        if (same == 1) {
            rich = max(rich, 50000 + *s.begin() * 5000);
        } else if (same == 2) {
            bool is_three = false;
            int three;

            for (auto i : s) {
                if (dice[i] == 3) {
                    is_three = true;
                    three = i;
                }
            }

            if (is_three) {
                rich = max(rich, 10000 + three * 1000);
            } else {
                vector<int> v;
                for (auto i : s) {
                    if (dice[i] == 2)
                        v.push_back(i);
                }

                rich = max(rich, 2000 + v[0] * 500 + v[1] * 500);
            }
        } else if (same == 3) {
            int two;
            for (auto i : s) {
                if (dice[i] == 2)
                    two = i;
            }

            rich = max(rich, 1000 + two * 100);
        } else {
            rich = max(rich, *max_element(s.begin(), s.end()) * 100);
        }
    }

    cout << rich;
}