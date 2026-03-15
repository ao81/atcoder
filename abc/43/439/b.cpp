#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int f(int n) {
	int res = 0;
	while (n) {
		int d = n % 10;
		res += d * d;
		n /= 10;
	}
	return res;
}

int main(void) {
	int n;
	cin >> n;

	rep (i, 1000) {
		n = f(n);
	}

	if (n == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}