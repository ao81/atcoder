#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	string a = "abcdefgh";
	int ok = 0;
	for (int i = 8; i >= 1; i--) {
		string s;
		cin >> s;
		rep(j, 0, 8) {
			if (s[j] == '*') {
				cout << a[j];
				ok = 1;
				break;
			}
		}
		if (ok) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}