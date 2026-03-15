#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int &a : t) cin >> a;
	vector<int> rank(n);
	for (int i = 0; i < n; i++) {
		rank[i] = i + 1;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i] > t[j]) {
				swap(t[i], t[j]);
				swap(rank[i], rank[j]);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << rank[i] << " ";
	}
	cout << endl;

	return 0;
}