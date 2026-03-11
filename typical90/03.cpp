#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int n, max_d, far_v;
vvl g;

void dfs(int v, int p, int d) {
	if (d > max_d) {
		max_d = d;
		far_v = v;
	}
	for (int next : g[v]) {
		if (next != p) {
			dfs(next, v, d + 1);
		}
	}
}

int main(void) {
	cin >> n;
	g.resize(n);
	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	max_d = -1;
	dfs(0, -1, 0);

	max_d = -1;
	dfs(far_v, -1, 0);

	cout << max_d + 1 << endl;
	return 0;
}