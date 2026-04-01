#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	vl a(n), p(n);
	rep(i, 0, n) cin >> a[i];

	vector<bool> used(n + 1, false);
	rep(i, 0, n) {
		if (a[i] != -1) {
			if (used[a[i]]) {
				cout << "No\n";
				return 0;
			}
			used[a[i]] = true;
			p[i] = a[i];
		}
	}

	int val = 1;
	rep(i, 0, n) {
		if (a[i] == -1) {
			while (used[val]) val++;
			p[i] = val++;
		}
	}

	cout << "Yes\n";
	rep(i, 0, n) cout << p[i] << " ";
	cout << "\n";
	return 0;
}