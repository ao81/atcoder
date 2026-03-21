#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int h, w;
vector<string> s;
vector<vector<bool>> visited;
bool touch;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int i, int j) {
	visited[i][j] = true;
	if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
		touch = true;
	}
	rep(d, 0, 4) {
		int ni = i + dx[d];
		int nj = j + dy[d];
		if (ni >= 0 && ni < h && nj >= 0 && nj < w && s[ni][nj] == '.' && !visited[ni][nj]) {
			dfs(ni, nj);
		}
	}
}

int main(void) {
	cin >> h >> w;
	s.resize(h);
	rep(i, 0, h) cin >> s[i];
	visited.assign(h, vector<bool>(w, false));
	int ans = 0;
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (s[i][j] == '.' && !visited[i][j]) {
				touch = false;
				dfs(i, j);
				if (!touch) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}