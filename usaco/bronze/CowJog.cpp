#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);
  int n, t;
  cin >> n >> t;
  vector<long long> dp;
  for (int i = 0; i < n; i++) {
    long long x, s;
    cin >> x >> s;
    x = -(x + t * s);
    if (dp.empty() || x >= dp.back()) {
      dp.push_back(x);
    }else{
      *upper_bound(dp.begin(), dp.end(), x) = x;
    }
  }

  cout << dp.size() << endl;
  return 0;
}