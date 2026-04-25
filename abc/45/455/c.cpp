#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

int main(void) {
	int n, k;
	cin >> n >> k;
	vl a(n);
	rep(i, 0, n) cin >> a[i];
	ll total = 0;
	rep(i, 0, n) total += a[i];
	map<ll, ll> cnt;
	rep(i, 0, n) cnt[a[i]]++;
	vector<pl> v(all(cnt));
	sort(all(v), [](const pl& a, const pl& b) {
		return a.first * a.second < b.first * b.second;
	});
	reverse(all(v));
	int use = min(k, (int)v.size());
	ll remove = 0;
	rep(i, 0, use) remove += v[i].first * v[i].second;
	cout << total - remove << endl;
	return 0;
}