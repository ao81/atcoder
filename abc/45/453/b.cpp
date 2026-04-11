#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int t, x; cin >> t >> x;
	vl a(t + 1);
	rep(i, 0, t) cin >> a[i];
	int last = a[0];
	cout << 0 << " " << a[0] << "\n";
	rep(i, 1, t) {
		if (abs(a[i] - last) >= x) {
			cout << i << " " << a[i] << "\n";
			last = a[i];
		}
	}
	return 0;
}