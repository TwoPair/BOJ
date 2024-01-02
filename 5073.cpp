#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (!a) break;

        // not triangle?
        int longest = max({a, b, c});
        int rest = (a + b + c) - longest;

        if (longest >= rest) {
            cout << "Invalid\n";
            continue;
        }

        // which type
        set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);

        int cnt = s.size();
        string str = "Scalene";

        if (cnt == 1)
            str = "Equilateral";
        else if (cnt == 2)
            str = "Isosceles";

        cout << str << "\n";
    }
}