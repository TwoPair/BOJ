#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;

ll digit[2][10];
int n;

ll myfunc(int x, int y) {return (x + y) % ll(1e9); }

int main() {
    int src = 0, dst = 1;
    cin >> n;

    // init for "round 1"
    fill(digit[src], digit[src] + 10, 1);
    fill(digit[dst], digit[dst] + 10, 0);
    digit[src][0] = 0;

    // do dp
    swap(src, dst);
    for (int round = 2; round <= n; round++) {
        swap(src, dst);

        digit[dst][0] += digit[src][1];
        digit[dst][9] += digit[src][8];
        for (int i = 1; i <= 8; i++)
            digit[dst][i] += (digit[src][i - 1] + digit[src][i + 1]) % ll(1e9);

        fill(digit[src], digit[src] + 10, 0);
    }

    cout << accumulate(digit[dst], digit[dst] + 10, 0, myfunc);
}