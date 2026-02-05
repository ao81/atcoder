#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using pl = pair<int, int>;
using vl = vector<int>;
using vvl = vector<vector<int>>;

int main(void) {
	int h, b, ans = 0;
	cin >> h >> b;
	if (h > b) {
		ans = h - b;
	} else {
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}