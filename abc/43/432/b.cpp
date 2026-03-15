#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int x;
	cin >> x;
	int len = to_string(x).length();
	vector<int> a(len);
	rep(i, len) {
		a[i] = x % 10;
		x /= 10;
	}
	sort(a.begin(), a.end());
	if (*a.begin() == 0) {
		rep(i, len - 1) {
			if (a[i + 1] != 0) {
				swap(a[0], a[i + 1]);
				break;
			}
		}
	}
	rep(i, len) {
		cout << a[i];
	}
	cout << endl;

	return 0;
}