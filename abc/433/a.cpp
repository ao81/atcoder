#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void) {
	int x, y, z;
	cin >> x >> y >> z;
	int res = 0;
	rep(i, 100) {
		if (x == (y * z)) {
			res = 1;
			break;
		}
		x++, y++;
	}
	if (res) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}