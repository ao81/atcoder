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
	vl a(n);
	rep(i, 0, n) {
		cin >> a[i];
		a[i]--;
	}
	vl ans(n);
	for (int i = n - 1; i >= 0; i--) {
		if (i == a[i]) ans[i] = i;
		else ans[i] = ans[a[i]];
	}
	rep(i, 0, n) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}