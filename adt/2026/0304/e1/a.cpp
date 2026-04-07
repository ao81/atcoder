#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  while (n != s.length()) {
    s.insert(0, "o");
  }
  cout << s << endl;
  return 0;
}
