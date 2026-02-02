#include <iostream>
using namespace std;

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	while (n > s.length()) {
		s = 'o' + s;
	}
	cout << s << endl;
	return 0;
}