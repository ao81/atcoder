#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m; cin >> n >> m;
	vvl g(n + 1);
	vector<bool> have(n + 1, false);
	queue<int> q;
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}

	have[1] = true;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : g[cur]) {
			if (!have[next]) {
				have[next] = true;
				q.push(next);
			}
		}
	}

	int ans = 0;
	rep(i, 1, n + 1) if (have[i]) ans++;
	cout << ans << "\n";
	
	return 0;
}