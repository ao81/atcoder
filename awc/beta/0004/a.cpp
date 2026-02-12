#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, s, t, total = 0;
	cin >> n >> s >> t;
	rep(i, 0, n) {
		int a;
		cin >> a;
		total += a;
	}
	int h = total / 60;
	int m = total % 60;
	if (m > 0) h++;
	if (s + h <= t) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}