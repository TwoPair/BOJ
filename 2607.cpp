#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void build_map(const string& s, map<char, int>& m) {
    for (char c : s) {
        if (m.find(c) != m.end())
            m[c]++;
        else
            m[c] = 1;
    }
}

int main() {
    int n, cnt_similar = 0;
    string o;
    cin >> n >> o;

    n--;
    while (n--) {
        string origin = o, cmp, final;
        cin >> cmp;

        // cmp string should be longer than origin string.
        if (origin.length() > cmp.length())
            swap(origin, cmp);
        
        map<char, int> m_origin;
        build_map(origin, m_origin);

        for (char c : cmp) {
            if (m_origin[c] > 0)
                m_origin[c]--;
            else
                final += c;
        }

        int size = final.size();
        if (size == 0 || size == 1)
            cnt_similar++;
    }

    cout << cnt_similar;
}