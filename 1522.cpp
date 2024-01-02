#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    // I'll count 'b' for grouping them.
    int size = count(str.begin(), str.end(), 'b');

    str += str; // Input string is circular, so attach itself to the end.

    /**
     * Concept: Sliding window
     * 
     * window size: `size` variable
     * 
     */
    queue<int> q;
    int ans = size;     // The maximum exchange arise as the count of 'b'.
    for (int i = 0; i < str.length(); i++) {
        // if the first location of 'b' is out of range of `size`,
        // it should be get rid of queue.
        if (!q.empty() && i - q.front() >= size) q.pop();
        if (str[i] == 'b') q.push(i);
        // size - q.size() => exchange count of 'a'
        ans = min(ans, size - (int)q.size());
    }

    cout << ans;
}
