#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
	int n, a = 0, b = 0;
	cin >> n;
	vector<int> arr(n);
	rep(i, n) cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());
	rep(i, n) {
		if (i % 2 == 0) a += arr[i];
		else b += arr[i];
	}
	cout << a - b << endl;
	return 0;
}