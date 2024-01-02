#include <iostream>
#include <string>
using namespace std;

// brute force solving
int main() {
    int n, count = 0, num = 665;
    cin >> n;

    while (n != count) {
        num++;
        if (to_string(num).find("666") != string::npos)
            count++;
    }

    cout << num;
}