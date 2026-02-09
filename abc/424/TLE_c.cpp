#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> ab(n + 1);
	rep(i, 1, n + 1) cin >> ab[i].first >> ab[i].second;
	vector<bool> res(n + 1, false);
	rep(i, 1, n + 1) {
		if (ab[i].first == 0 && ab[i].second == 0) {
			res[i] = true;
		}
	}
	bool updated = true;
	while (updated) {
		updated = false;
		rep(i, 1, n + 1) {
			if (res[i]) continue;
			auto [a, b] = ab[i];
			if (res[a] || res[b]) {
				res[i] = true;
				updated = true;
			}
		}
	}
	cout << count(all(res), true) << endl;
	return 0;
}