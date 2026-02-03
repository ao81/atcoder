#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int n, res = 0;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	while (1) {
		int iseven = 1;
		rep(i, n) {
			if (a[i] % 2 == 0) a[i] /= 2;
			else {
				iseven = 0;
				break;
			}
		}
		if (iseven) res++;
		else break;
	}
	cout << res << endl;
	return 0;
}