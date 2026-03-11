#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int h, w;
	cin >> h >> w;
	vvl a(h, vl(w));
	rep(i, 0, h) {
		rep(j, 0, w) {
			cin >> a[i][j];
		}
	}

	vl row(h, 0), col(w, 0);
	rep(i, 0, h) {
		rep(j, 0, w) {
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}

	rep(i, 0, h) {
		rep(j, 0, w) {
			cout << row[i] + col[j] - a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}