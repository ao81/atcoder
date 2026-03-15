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
	vector<int> res(200010, 0);
	cin >> n;
	rep(i, 0, n) {
		int a;
		cin >> a;
		if (a <= 0) continue;
		res[0]++;
		res[a]--;
	}
	rep(i, 0, 200005) res[i + 1] += res[i];
	rep(i, 0, 200005) {
		if (res[i] >= 2) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
	int maxidx = 200005;
	while (maxidx >= 0 && res[maxidx] == 0) maxidx--;
	for (int i = maxidx; i >= 0; i--) cout << res[i];
	cout << endl;
	return 0;
}