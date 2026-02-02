#include <iostream>
using namespace std;

int main(void) {
	int w, b;
	cin >> w >> b;
	w *= 1000;
	int n = 0;
	while (w >= n * b) {
		n++;
	}
	cout << n << endl;
	return 0;
}