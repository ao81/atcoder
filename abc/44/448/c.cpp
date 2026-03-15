#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, q;
	cin >> n >> q;
	vl a_(n);
	rep(i, 0, n) cin >> a_[i];
	vector<pl> a(n);
	rep(i, 0, n) a[i] = { a_[i], i + 1 };
	sort(all(a));
	rep(i, 0, q) {
		int k;
		cin >> k;

		vl rem(k);
		rep(j, 0, k) cin >> rem[j];
		sort(all(rem));

		rep(j, 0, n) {
			if (find(all(rem), a[j].second) == rem.end()) {
				cout << a[j].first << endl;
				break;
			}
		}
	}
	return 0;
}