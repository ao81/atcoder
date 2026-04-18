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
	vl f(n); rep(i, 0, n) cin >> f[i];

	bool ans1 = true;
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			if (f[i] == f[j]) {
				ans1 = false;
				break;
			}
		}
	}

	bool ans2 = true;
	rep(i, 1, m + 1) {
		bool found = false;
		rep(j, 0, n) {
			if (f[j] == i) {
				found = true;
				break;
			}
		}
		if (!found) {
			ans2 = false;
			break;
		}
	}

	cout << (ans1 ? "Yes" : "No") << "\n";
	cout << (ans2 ? "Yes" : "No") << "\n";

	return 0;
}