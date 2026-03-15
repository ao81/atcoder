#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int a = -1;
		for (int j = i; j >= 0; j--) {
			if (arr[i] < arr[j]) {
				a = j + 1;
				break;
			}
		}
		cout << a << endl;
	}
	return 0;
}