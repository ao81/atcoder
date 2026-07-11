#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<int>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m;
	cin >> n >> m;
	vl mx(m + 1, -1);
	rep(i, 0, n) {
		int c, s;
		cin >> c >> s;
		mx[c] = max(mx[c], s);
	}
	rep(i, 1, m + 1) cout << mx[i] << " ";
	cout << "\n";
	return 0;
}