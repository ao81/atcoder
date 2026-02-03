#include <bits/stdc++.h>
using namespace std;

string s, words[4] = { "dream", "dreamer", "erase", "eraser" };

bool f(int pos) {
	if (pos == 0) return true;

	bool res = false;
	for (string w : words) {
		int len = w.length();
		if (pos >= len && s.substr(pos - len, len) == w) {
			if (f(pos - len)) {
				res = true;
				break;
			}
		}
	}
	return res;
}

int main(void) {
	cin >> s;
	if (f(s.length())) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}