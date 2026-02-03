#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			for (int k = 0; k <= n - i - j; k++) {
				if ((i*10000 + j*5000 + k*1000 == y) && i+j+k == n) {
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}