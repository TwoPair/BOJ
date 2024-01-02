#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

/** 단순히 알고리즘적으로 생각해서 풀려는 것도 중요하지만
 * 사고의 방식을 달리 해서 푸는 것 또한 중요하다!
 *
 * 이 문제에선 아래와 같이 하나하나 붙여가면서 하는 방법도 있지만,
 * stack, deque와 같은 자료구조를 이용하여 데이터를 그때그때 확인하는 방법도 유효하다.
 **/

string s, target, t;

void removeTarget() {
    int tgLen = target.length();
    for (auto c: s) {
        t += c;
        if (t.length() >= tgLen) {
            if (equal(t.end() - tgLen, t.end(), target.begin(), target.end()))
                for (int i = 0; i < tgLen; ++i)
                    t.pop_back();
        }
    }
}

int main() {
    fastio
    cin >> s >> target;

    removeTarget();

    if (t.length() == 0)
        cout << "FRULA";
    else
        cout << t;
}