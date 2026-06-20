#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	char x; cin >> x;

	bool ok = false;
	rep(i, 0, n) {
		string s; cin >> s;
		int n = x - 'A';
		if (s[n] == 'o') ok = true;
	}

	cout << (ok ? "Yes\n" : "No\n");
	return 0;
}