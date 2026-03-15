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
	vector<pair<string, string>> name(n);
	for (auto& [s, t]: name) cin >> s >> t;
	bool ans = false;
	rep(i, 0, n - 1) {
		rep(j, i + 1, n) {
			if (name[i] == name[j]) {
				ans = true;
				break;
			}
		}
		if (ans) break;
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}