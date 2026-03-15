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
	vvl ab(n);
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		ab[a-1].push_back(b-1);
		ab[b-1].push_back(a-1);
	}
	rep(i, 0, n) {
		ll c = n - 1 - ab[i].size();
		cout << c * (c-1) * (c-2) / 6 << " ";
	}
	cout << endl;
	return 0;
}