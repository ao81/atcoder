#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, a[50] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int s = 0;
			for (int k = j; k <= i; k++) s += a[k];
			int ok = true;
			for (int k = j; k <= i; k++) if (s % a[k] == 0) ok = false;
			if (ok) res++;
		}
	}
	cout << res << endl;
	return 0;
}