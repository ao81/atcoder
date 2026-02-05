#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, ans = 0, max = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		ans++;
		int v = i + 1 + a[i];
		if (v > max) max = v;
		if (i + 2 >= max) break;
	}
	cout << ans << endl;
	return 0;
}