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
	pair<int, int> ans;
	rep(i, 0, n) {
		int h; cin >> h;
		ans = max(ans, {h, i + 1});
	}
	cout << ans.second << endl;
	return 0;
}