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
	ll ans = 0;
	int r = 1;
	auto q = [&](int i, int j) -> bool {
		cout << "? " << i << " " << j << endl;
		string res; cin >> res;
		return (res == "Yes");
	};

	rep(i, 1, n + 1) {
		if (r < i) r = i;
		while (r < n && q(i, r + 1)) r++;
		ans += r - i;
	}

	cout << "! " << ans << endl;
	return 0;
}
