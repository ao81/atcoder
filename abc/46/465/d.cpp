#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int t; cin >> t;
	while (t--) {
		ll x, y, k;
		cin >> x >> y >> k;
		int cnt = 0;
		while (x != y) {
			if (x > y) x /= k;
			else y /= k;
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}