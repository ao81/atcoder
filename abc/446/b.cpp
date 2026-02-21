#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<bool> used(m + 1, false);
	vector<int> ans(n);
	rep(i, 0, n) {
		int l;
		cin >> l;
		int choose = -1;
		rep(j, 0, l) {
			int x;
			cin >> x;
			if (choose == -1 && !used[x]) {
				choose = x;
				used[x] = true;
			}
		}
		if (choose == -1) choose = 0;
		ans[i] = choose;
	}
	rep(i, 0, n) {
		cout << ans[i] << endl;
	}
	return 0;
}