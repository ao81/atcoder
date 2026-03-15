#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using pl = pair<int, int>;
using vl = vector<int>;
using vvl = vector<vector<int>>;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (c >= a && d < b) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}