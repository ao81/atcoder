#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, min = 101;
	cin >> n;
	rep(i, 0, n) {
		int t; cin >> t;
		if (min > t) min = t;
	}
	cout << min << endl;
	return 0;
}