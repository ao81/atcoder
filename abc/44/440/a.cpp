#include <iostream>
using namespace std;

int main(void) {
	int x, y;
	cin >> x >> y;
	while (y--) {
		x *= 2;
	}
	cout << x << endl;
	return 0;
}