#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n; cin >> n;
	vvl C(n + 1, vl(n + 1));
	rep(i, 1, n) {
		rep(j, i+1, n) {
			cin >> C[i][j];
		}
	}
	rep(a, 1, n) {
		rep(c, a+2, n) {
			rep(b, a+1, c-1) {
				if (C[a][c] > C[a][b] + C[b][c]) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}