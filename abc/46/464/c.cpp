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
	vl a(n), d(n), b(n);
	rep(i, 0, n) cin >> a[i] >> d[i] >> b[i];

	vvl change(m + 1);
	vl cnt(n + 1, 0);
	int k = 0;

	auto add = [&](int c) {
		if (cnt[c] == 0) k++;
		cnt[c]++;
	};
	auto del = [&](int c) {
		cnt[c]--;
		if (cnt[c] == 0) k--;
	};

	rep(i, 0, n) {
		if (d[i] == 1) add(b[i]);
		else {
			add(a[i]);
			change[d[i]].push_back(i);
		}
	}
	rep(day, 1, m + 1) {
		for (int i : change[day]) {
			del(a[i]);
			add(b[i]);
		}
		cout << k << "\n";
	}

	return 0;
}