#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string s, alpa = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	rep(i, 0, 26) {
		bool ok = true;
		rep(j, 0, (int)s.length()) {
			if (alpa[i] == s[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << alpa[i] << endl;
			break;
		}
	}
	return 0;
}