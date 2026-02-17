#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (auto& a : h) cin >> a;
	vector<int> dp(n);

	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		int min = 1e9;
		for (int j = 1; j <= k && i - j >= 0; j++) {
			int a = dp[i - j] + abs(h[i] - h[i - j]);
			if (min > a) min = a;
		}
		dp[i] = min;
	}

	cout << dp[n - 1] << endl;
	return 0;
}