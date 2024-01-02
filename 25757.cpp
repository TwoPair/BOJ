#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    char game;
    string name;
    set<string> list;

    cin >> n >> game;
    while (n--) {
        cin >> name;
        list.insert(name);
    }

    int div = 1;
    if (game == 'F') div += 1;
    if (game == 'O') div += 2;

    cout << list.size() / div;
}