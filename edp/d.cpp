#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	ll n, w;
	cin >> n >> w;
	vl dp(w + 1, 0);

	for (int i = 0; i < n; i++) {
		ll wi, vi;
		cin >> wi >> vi;

		for (int j = w; j >= wi; j--) {
			dp[j] = max(dp[j], dp[j - wi] + vi);
		}
	}

	cout << dp[w] << endl;
	return 0;
}