#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s, t;
	cin >> s >> t;
	int slen = s.length(), tlen = t.length();
	int i = 0, j = 0;
	ll ans = 0, scnt, tcnt;
	while (i < slen || j < tlen) {
		scnt = tcnt = 0;

		while (i < slen && s[i] == 'A') i++, scnt++;
		while (j < tlen && t[j] == 'A') j++, tcnt++;

		ans += llabs(scnt - tcnt);

		if (i == slen && j == tlen) break;

		if (i == slen || j == tlen) {
			ans = -1;
			break;
		}

		if (s[i] != t[j]) {
			ans = -1;
			break;
		}

		i++, j++;
	}
	cout << ans << endl;
	return 0;
}