#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int h, w, q;
	cin >> h >> w >> q;
	rep(i, 0, q) {
		int n, rc, ans;
		cin >> n >> rc;
		if (n == 1) {
			ans = w * rc;
			h -= rc;
		} else {
			ans = h * rc;
			w -= rc;
		}
		cout << ans << endl;
	}
	return 0;
}