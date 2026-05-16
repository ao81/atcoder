#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s; cin >> s;
	int n = s.size();
	ll cnt = 0;

	rep(i, 0, n) {
		if (s[i] == 'C') {
			ll left = i;
			ll right = n - 1 - i;
			cnt += min(left, right) + 1;
		}
	}

	cout << cnt << "\n";
	return 0;
}