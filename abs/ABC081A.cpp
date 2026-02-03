#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		if ((n >> i & 1) == 1) res++;
	}
	cout << res << endl;
	return 0;
}