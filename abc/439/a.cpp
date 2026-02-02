#include <iostream>
using namespace std;

int main(void) {
	int n, a = 1;
	cin >> n;
	int n_ = n;
	while (n_--) a *= 2;
	cout << a - 2 * n << endl;
	return 0;
}