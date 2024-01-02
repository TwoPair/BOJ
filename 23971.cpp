#include <iostream>
using namespace std;

int main() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int total = 0;
    N++; M++;
    
    // 가로 w, m
    // 세로 h, n
    total = (W / M) + ((W % M) != 0 ? 1 : 0);
    total = total * ((H / N) + ((H % N) != 0 ? 1 : 0));

    cout << total;
}
