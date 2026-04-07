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
	string s;
	cin >> n >> s;
	bool pass = false;
	rep(i, 0, n) {
		if (s[i] == 'x') {
			pass = false;
			break;
		}
		if (s[i] == 'o') {
			pass = true;
		}
	}
	if (pass) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}