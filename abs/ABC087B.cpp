#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= n; i++)

int main(void) {
	int a, b, c, x, res = 0;
	cin >> a >> b >> c >> x;
	rep(i, a) {
		rep(j, b) {
			rep(k, c) {
				if (i*500 + j*100 + k*50 == x) res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}