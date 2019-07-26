#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef map<string, pair<string, int> > DS;

string Find(DS &ds, string &x) {
	if (ds[x].fi == "") return x;
	else {
		ds[x].fi = Find(ds, ds[x].fi);
		return ds[x].fi;
	}
}

void Union(DS &ds, string rt1, string rt2) {
	if (rt1 != rt2) {
		if (ds[rt1].se > ds[rt2].se) ds[rt2].fi = rt1, ds[rt1].se += ds[rt2].se;
		else ds[rt1].fi = rt2, ds[rt2].se += ds[rt1].se;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q, f; cin >> q;

	while (q--) {
		DS m;
		string n1, n2;
		cin >> f;

		while (f--) {
			cin.ignore();
			cin >> n1 >> n2;
			if (m.find(n1) == m.end()) m.insert({ n1, { "", 1 } });
			if (m.find(n2) == m.end()) m.insert({ n2, { "", 1 } });

			Union(m, Find(m, n1), Find(m, n2));
			cout << m[Find(m, n1)].se << '\n';
		}
	}
}