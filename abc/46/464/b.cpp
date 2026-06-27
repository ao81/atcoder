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
	char s[h][w];
	rep(i, 0, h) rep(j, 0, w) cin >> s[i][j];
	int t = 0;
	while (t < h) {
		bool ok = true;
		rep(i, 0, w) if (s[t][i] == '#') {
			ok = false;
			break;
		}
		if (ok) rep(i, 0, w) s[t][i] = 'a';
		else break;
		t++;
	}
	int b = h - 1;
	while (b >= 0) {
		bool ok = true;
		rep(i, 0, w) if (s[b][i] == '#') {
			ok = false;
			break;
		}
		if (ok) rep(i, 0, w) s[b][i] = 'a';
		else break;
		b--;
	}
	int l = 0;
	while (1) {
		bool ok = true;
		rep(i, 0, h) if (s[i][l] == '#') {
			ok = false;
			break;
		}
		if (ok) rep(i, 0, h) s[i][l] = 'a';
		else break;
		l++;
	}
	int r = w - 1;
	while (1) {
		bool ok = true;
		rep(i, 0, h) if (s[i][r] == '#') {
			ok = false;
			break;
		}
		if (ok) rep(i, 0, h) s[i][r] = 'a';
		else break;
		r--;
	}
	rep(i, 0, h) {
		int all = true;
		rep(j, 0, w) if (s[i][j] != 'a') {
			all = false;
			break;
		}
		if (all) continue;
		rep(j, 0, w) if (s[i][j] != 'a') cout << s[i][j];
		cout << "\n";
	}
	return 0;
}