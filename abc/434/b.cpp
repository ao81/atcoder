#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(2, vector<int>(m + 1, 0));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[0][a - 1] += b;
		arr[1][a - 1]++;
	}
	for (int i = 0; i < m; i++) {
		float ans = (float)arr[0][i] / arr[1][i];
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}