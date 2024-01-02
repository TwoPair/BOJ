#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/** 현재 풀이 : DFS **/
/** 제한이 작아서 DFS로도 풀리지만 Disjoint Set & Union-find 기법으로 푸는게 더 빠르다! **/

enum State {
    LIED, TRUTH, PURE
};

enum Type {
    BOTH, DO_LIE, DO_TRUTH, MIX
};

struct Person {
    int idx;
    State heard;
};

int N, M, result = 0;
vector<State> know;
vector<vector<int>> come;

Type canLie(int day) {
    int count[] = { 0, 0, 0 }; // 0: LIED, 1: TRUTH, 2: PURE
    for (auto idx: come[day])
        count[know[idx]]++;

    if (count[LIED] > 0 && count[TRUTH] > 0)
        return MIX;
    else if (count[LIED] == 0 && count[TRUTH] == 0)
        return BOTH;
    else if (count[LIED] > 0 && count[TRUTH] == 0)
        return DO_LIE;
    else if (count[LIED] == 0 && count[TRUTH] > 0)
        return DO_TRUTH;
}

void theyKnowNow(int day, State heard, queue<int>& pured) {
    for (auto idx: come[day]) {
        if (know[idx] == PURE) {
            know[idx] = heard;
            pured.push(idx);
        }
    }
}

void previousState(queue<int>& pured) {
    while (!pured.empty()) {
        know[pured.front()] = PURE;
        pured.pop();
    }
}

// 거짓말을 들은 사람과 진실을 들은 사람이 섞여 있으면 말을 못하니 갱신하지 않도록 로직을 짜자
void dfs(int today, int totalLieDay) {
    if (today == M) {
        result = max(result, totalLieDay);
        return;
    }

    queue<int> pured;
    switch (canLie(today)) {
        case MIX:
            return;
        case DO_LIE:
            theyKnowNow(today, LIED, pured);
            dfs(today + 1, totalLieDay + 1);
            previousState(pured);
            break;
        case DO_TRUTH:
            theyKnowNow(today, TRUTH, pured);
            dfs(today + 1, totalLieDay);
            previousState(pured);
            break;
        case BOTH:
            theyKnowNow(today, LIED, pured);
            dfs(today + 1, totalLieDay + 1);
            previousState(pured);

            theyKnowNow(today, TRUTH, pured);
            dfs(today + 1, totalLieDay);
            previousState(pured);
            break;
    }
}

void solve() {
    dfs(0, 0);
    cout << result;
}

int main() {
    cin >> N >> M;
    know.resize(N + 1, PURE);
    come.resize(M + 1);

    int who, i;
    cin >> who;
    while (who--) {
        cin >> i;
        know[i] = TRUTH;
    }

    for (int j = 0; j < M; ++j) {
        cin >> who;
        while (who--) {
            cin >> i;
            come[j].push_back(i);
        }
    }

    solve();
}