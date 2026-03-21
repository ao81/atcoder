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
	vector<int> q(n + 1), p(n + 1), a(n + 1);
	rep(i, 1, n + 1) cin >> p[i];
	rep(i, 1, n + 1) cin >> q[i];

	rep(i, 1, n + 1) a[q[i]] = i;
	rep(i, 1, n + 1) cout << q[p[a[i]]] << " ";
	cout << endl;
	
	return 0;
}