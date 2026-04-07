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
	vector<string> s(n);
	rep(i, 0, n) cin >> s[i];
	set<string> ans;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i == j) continue;
			ans.insert(s[i] + s[j]);
		}
	}
	cout << ans.size() << endl;
	return 0;
}