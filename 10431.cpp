#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve() {
    // input
    int idx;
    cin >> idx;

    int tall[20];
    for (int i = 0; i < 20; i++) cin >> tall[i];

    // work
    int total_move = 0;
    vector<int> stand;
    stand.push_back(tall[0]);

    for (int i = 1; i < 20; i++) {
        vector<int>::iterator low = lower_bound(stand.begin(), stand.end(), tall[i]);

        int move = i - (low - stand.begin());
        total_move += move;
        stand.insert(low, tall[i]);

        // for (int k = 0; k <= i; k++)
        //     cout << stand[k] << " ";
        // cout << ": ";
    }

    return total_move;
}

int main() {
    int P;
    cin >> P;

    for (int i = 1; i <= P; i++)
        cout << i << " " << solve() << "\n";
}
