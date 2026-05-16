#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int h, w; cin >> h >> w;
	rep(i, 0, h) {
		rep(j, 0, w) {
			int count = 0;
			if (i > 0) count++;
			if (i < h - 1) count++;
			if (j > 0) count++;
			if (j < w - 1) count++;
			if (j > 0) cout << " ";
			cout << count;
		}
		cout << "\n";
	}
	return 0;
}