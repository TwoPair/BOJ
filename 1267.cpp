#include <iostream>
using namespace std;

int main() {
    int n, time, y = 0, m = 0;
    cin >> n;

    while (n--) {
        cin >> time;
        y += (time / 30 + 1) * 10;
        m += (time / 60 + 1) * 15;
    }

    if (y == m) cout << "Y M " << y;
    else if (y < m) cout << "Y " << y;
    else cout << "M " << m;
}