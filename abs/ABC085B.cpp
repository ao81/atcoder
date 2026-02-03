#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void) {
	int n, d;
	cin >> n;
	set<int> s;
	rep(i, n) {
		cin >> d;
		s.insert(d);
	}
	cout << s.size() << endl;
	return 0;
}