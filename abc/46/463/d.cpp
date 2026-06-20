#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, k; cin >> n >> k;
	vector<pl> lr(n);
	rep(i, 0, n) cin >> lr[i].first >> lr[i].second;
	sort(all(lr), [](const pl& a, const pl& b) {
		return a.second < b.second;
	});

	auto check = [&](ll d) {
		ll lastr = LLONG_MIN / 2;
		int cnt = 0;
		rep(i, 0, n) {
			if (lr[i].first - lastr >= d) {
				lastr = lr[i].second;
				cnt++;
			}
		}
		return cnt >= k;
	};

	if (!check(1)) {
		cout << -1 << "\n";
		return 0;
	}

	ll ok = 1, ng = 1e9;
	while (ng - ok > 1) {
		ll mid = (ok + ng) / 2;
		if (check(mid)) ok = mid;
		else ng = mid;
	}

	cout << ok << "\n";
	return 0;
}