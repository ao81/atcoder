#include <bits/stdc++.h>
using namespace std;

int digsum(int n) {
	if (n < 10) return n;
	else return (n % 10) + digsum(n / 10);
}

int main(void) {
	int n, a, b, res = 0;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		int x = digsum(i);
		if (a <= x && x <= b) res += i;
	}
	cout << res << endl;
	return 0;
}