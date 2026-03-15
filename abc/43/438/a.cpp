#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int d, f;
	cin >> d >> f;

	while (f <= d) {
		f += 7;
	}
	cout << f - d << endl;

	return 0;
}