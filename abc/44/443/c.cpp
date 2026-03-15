#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int n, t, a, res = 0, next = 0;
	cin >> n >> t;
	rep(i, n) {
		cin >> a;
		if (a > next) {
			res += a - next;
			next = a + 100;
		}
	}
	if (t > next) {
		res += t - next;
	}
	cout << res << endl;
	return 0;
}