#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, a[3] = {0};
	cin >> n;
	rep(i, 0, 6) {
		int s = n % 10;
		if (s == 1) a[0]++;
		else if (s == 2) a[1]++;
		else if (s == 3) a[2]++;
		n /= 10;
	}
	if (a[0] == 1 && a[1] == 2 && a[2] == 3) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}