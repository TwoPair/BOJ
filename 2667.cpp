#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
//mt19937 mrand(random_device{}());
const ll mod = 1000000007;
//int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a%mod; a = a * a%mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// head

char graph[28][28];
int danji;
VI homeCnt;
PII d[4] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };

void BFS(PII start) {
	int home = 1, x, y;
	queue<PII > q;
	graph[start.fi][start.se] = 0;

	q.push(start);
	PII nowVertex;

	while (!q.empty()) {
		nowVertex = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			x = nowVertex.fi + d[i].fi;
			y = nowVertex.se + d[i].se;
			if (graph[x][y] == '1') {
				++home;
				graph[x][y] = '0';
				q.push({ x, y });
			}
		}
	}

	homeCnt.pb(home);
} // End of "BFS"

int main() {
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();

	rep(i, 1, N + 1) rep(j, 1, N + 1)
		cin >> graph[i][j];

	rep(i, 1, N + 1) rep(j, 1, N + 1) {
		if (graph[i][j] == '1') {
			++danji;
			BFS(mp(i, j));
		}
	}

	cout << danji << '\n';
	sort(all(homeCnt));
	for (auto &i : homeCnt)
		cout << i << '\n';
}