#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <regex>
using namespace std;

/** 시도 1: regex를 이용해서 풀어보려 했지만 결국 O(n) = (N^2 x M) = N^3 으로 시간초과가 떴다. **/
//pair<int, int> calc_gap(const string &w, const vector<char> &q, int k) {
//    vector<int> result;
//
//    if (k == 1)
//        return {1, 1};
//
//    for (char target : q) {
//        string pattern =
//                "(?=(" + string(1, target) +
//                "(?:[^" + string(1, target) + "]*" + string(1, target) + ")" +
//                "{" + to_string(k - 2) + "}" +
//                "[^" + string(1, target) + "]*" +
//                string(1, target) + ")" +
//                ")";
//
//        regex regex_pattern(pattern);
//        smatch match;
//
//        for (sregex_iterator it(w.begin(), w.end(), regex_pattern); it != sregex_iterator(); ++it) {
//            string matched_str = it->str(1);
//            result.push_back(matched_str.length());
//        }
//    }
//
//    auto tmp = minmax_element(result.begin(), result.end());
//    return {*tmp.first, *tmp.second};
//}
//
//void solve() {
//    string w;
//    int k;
//
//    cin >> w >> k;
//
//    // count each alphabet
//    vector<int> alphabet(26, 0);
//    for (char c : w)
//        alphabet[c - 'a'] += 1;
//
//    // collect condition-satisfied alphabet
//    vector<char> q;
//    for (int i = 0; i < 26; i++)
//        if (alphabet[i] >= k)
//            q.push_back(i + 'a');
//
//    /* check nothing */
//    if (q.empty()) {
//        cout << "-1\n";
//        return;
//    }
//
//    // print the result
//    pair<int, int> result = calc_gap(w, q, k);
//    cout << result.first << " " << result.second << "\n";
//}

/** 시도 2: O(n) = N^2 **/
void solve() {
    string w;
    int k;
    map<char, vector<int>> m;

    cin >> w >> k;

    /* k is 1 */
    if (k == 1) {
        cout << "1 1\n";
        return;
    }

    // count each alphabet
    vector<int> alphabet(26, 0);
    for (char c : w)
        alphabet[c - 'a'] += 1;

    // collect condition-satisfied alphabet
    vector<char> q;
    for (int i = 0; i < 26; i++)
        if (alphabet[i] >= k)
            q.push_back(i + 'a');

    /* check nothing */
    if (q.empty()) {
        cout << "-1\n";
        return;
    }

    // insert each index
    for (char target : q) {
        for (int i = 0; i < w.length(); i++)
            if (w[i] == target)
                m[target].push_back(i);
    }

    // find them; guarantee that k >= 2
    vector<int> result;
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto index = it->second;
        for (int i = k - 1; i < index.size(); ++i)
            result.push_back((index[i] - index[i - k + 1]) + 1);
    }

    // print
    auto tmp = minmax_element(result.begin(), result.end());
    cout << *tmp.first << " " << *tmp.second << "\n";
}

int main() {
    int T;
    cin >> T;

    while (T--)
        solve();
}