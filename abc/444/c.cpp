#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	rep(i, 0, n) {
		cin >> a[i];
		sum += a[i];
	}
	sort(all(a));
	set<ll> res;

	rep(m, (n + 1) / 2, n + 1) {
		if (sum % m != 0) continue;
		ll l = sum / m;
		if (l < a[n - 1]) continue;
		bool ok = true;
		int k = n - m;
		rep(i, n - (m - k), n) {
			if (a[i] != l) {
				ok = false;
				break;
			}
		}
		if (ok) res.insert(l);
	}
	
	for (auto x : res) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}