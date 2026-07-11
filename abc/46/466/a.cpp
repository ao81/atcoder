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
	bool ok = true;
	rep(i, 0, n) {
		int a; cin >> a;
		if (a >= 0) ok = false;
	}
	cout << (ok ? "Yes\n" : "No\n");
	return 0;
}