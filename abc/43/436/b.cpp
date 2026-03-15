#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int n, r, c, k;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	r = 0, c = (n - 1) / 2, k = 1;
	a[r][c] = k;
	rep(i, n * n - 1) {
		int nr = (r - 1 + n) % n, nc = (c + 1) % n;
		if (a[nr][nc] == 0) {
			r = nr, c = nc;
		} else {
			r = (r + 1) % n;
		}
		a[r][c] = ++k;
	}
	rep(i, n) {
		rep(j, n) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}