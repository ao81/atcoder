#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, maxlen = 0;
	cin >> n;
	vector<string> s(n);
	rep(i, 0, n) {
		cin >> s[i];
		if (maxlen < (int)s[i].length()) maxlen = s[i].length();
	}
	rep(i, 0, n) {
		int len = s[i].length();
		int size = (maxlen - len) / 2;
		if (size > 0) {
			string padding(size, '.');
			cout << padding << s[i] << padding << endl;
		} else {
			cout << s[i] << endl;
		}
	}
	return 0;
}