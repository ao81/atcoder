#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, i = 0;
	cin >> n;
	vector<int> a(n);
	for (auto& aa : a) cin >> aa;
	while (i < (int)a.size() - 1) {
		if (abs(a[i] - a[i + 1]) == 1) i++;
		else if (a[i] < a[i + 1]) a.insert(a.begin() + i + 1, a[i] + 1);
		else if (a[i] > a[i + 1]) a.insert(a.begin() + i + 1, a[i] - 1);
	}
	for (auto aa : a) cout << aa << " ";
	cout << endl;
	return 0;
}