#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

vector<bool> seen;
vector<bool> ans;
map<ll, int> cnt;

void dfs(const vvl &g, const vl &a, int v, bool dup) {
    seen[v] = true;
    
    cnt[a[v]]++;
    if (cnt[a[v]] > 1) dup = true;
    ans[v] = dup;

    for (auto next_v : g[v]) { 
        if (seen[next_v]) continue;
        dfs(g, a, next_v, dup);
    }
    
    cnt[a[v]]--;
}

int main(void) {
	int n;
	cin >> n;
	vl a(n);
	vvl g(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	seen.assign(n, false);
	ans.assign(n, false);
	dfs(g, a, 0, false);
	rep(i, 0, n) {
		if (ans[i]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}