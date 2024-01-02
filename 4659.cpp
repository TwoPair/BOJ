#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string pw;

bool is_vowel(char c) {
    return (c == 'a') || (c == 'e') ||(c == 'i') ||(c == 'o') ||(c == 'u');
}

bool solve() {
    // 1. at least one vowel should be included.
    if (find_if(pw.begin(), pw.end(), is_vowel) == pw.end())
        return false;

    // 2. continuous vowels or consonant over 3 are banned.
    if (pw.length() >= 3) {
        vector<int> chk(pw.length(), 0);
        for (int i = 0; i < pw.length(); ++i) {
            if (is_vowel(pw[i]))
                chk[i] = 1;
        }

        for (int i = 0; i < pw.length() - 2; ++i) {
            int sum = chk[i] + chk[i + 1] + chk[i + 2];
            if (sum == 0 || sum == 3)
                return false;
        }
    }

    // 3. same characters more than two are not allowed except for 'ee' and 'oo'.
    for (int i = 1; i < pw.length(); ++i) {
        if (pw[i - 1] == pw[i]) {
            if (pw[i] == 'e' || pw[i] == 'o')
                continue;
            return false;
        }
    }

    return true;
}

int main() {
    while (true) {
        cin >> pw;
        if (pw == "end") break;

        printf("<%s> is %sacceptable.\n", pw.c_str(), (solve() ? "" : "not "));
    }
}