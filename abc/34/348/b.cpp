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
	vector<pair<int, int>> xy(n);
	for (auto& [x, y]: xy) cin >> x >> y;

	auto yq = [&](int a, int b) {
		return (xy[a].first - xy[b].first) * (xy[a].first - xy[b].first) + (xy[a].second - xy[b].second) * (xy[a].second - xy[b].second);
	};

	rep(i, 0, n) {
		pair<int, int> ans = {-1, n};
		rep(j, 0, n) {
			if (i == j) continue;
			int d = yq(i, j);
			if (d > ans.first || (d == ans.first && j + 1 < ans.second)) {
				ans = {d, j + 1};
			}
		}
		cout << ans.second << endl;
	}

	return 0;
}