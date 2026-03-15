#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ans(n, 0);
	rep(i, 0, k) {
		int a, b;
		cin >> a >> b;
		ans[a - 1]++;
		if (ans[a - 1] == m) cout << a << " ";
	}
	cout << endl;
	return 0;
}