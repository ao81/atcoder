#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, x, a;
	cin >> n >> x;
	rep(i, 0, n) {
		cin >> a;
		if (a < x) {
			x = a;
			cout << "1" << endl;
		} else {
			cout << "0" << endl;
		}
	}
	return 0;
}