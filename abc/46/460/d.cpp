// failed

#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;

int h, w;

vs step(const vs& g) {
	vs ng(h, string(w, '.'));
	const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	const int dy[] = { -1, 0, 1, -1, 1, -1, -0, 1 };

	rep(i, 0, h) rep(j, 0, w) {
		if (g[i][j] == '#') ng[i][j] = '.';
		else {
			bool b = false;
			rep(d, 0, 8) {
				int di = i + dx[d], dj = j + dy[d];
				if (di < 0 || di >= h || dj < 0 || dj >= w) continue;
				if (g[di][dj] == '#') {
					b = true;
					break;
				}
			}
			ng[i][j] = (b ? '#' : '.');
		}
	}

	return ng;
}

int main(void) {
	cin >> h >> w;
	vs s(h);
	rep(i, 0, h) cin >> s[i];

	vs prev = s;
	int t = 0;
	while (true) {
		vs nx = step(s);
		t++;
		if (t >= 2 && nx == prev) break;
		prev = s;
		s = nx;
	}

	rep(i, 0, h) cout << s[i] << "\n";
	return 0;
}