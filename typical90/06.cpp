#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int k, n, pos = 0;
	string s, ans;
	cin >> n >> k >> s;
	rep(i, 0, k) {
		int nokori = k - i;
		auto m = min_element(s.begin() + pos, s.begin() + (n - nokori + 1));
		ans += *m;
		pos = m - s.begin() + 1;
	}
	cout << ans << endl;
	return 0;
}