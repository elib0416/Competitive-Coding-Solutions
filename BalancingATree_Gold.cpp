#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n + 1);
		vector<int> l(n + 1);
		vector<int> r(n + 1);
		for (int i = 2; i <= n; ++i) {
			cin >> p[i];
		}
		int ans = 0;
		vector<pair<int, int>> bounds(n + 1);
		pair<int, int> pa{INT_MAX, INT_MIN};
		for (int i = 1; i <= n; ++i) {
			cin >> l[i] >> r[i];
			bounds[i] = {r[i], l[i]};
			pa.first = min(pa.first, bounds[i].first);
			pa.second = max(pa.second, bounds[i].second);
			if (i > 1) {
				bounds[i].first = min(bounds[i].first, bounds[p[i]].first);
				bounds[i].second = max(bounds[i].second, bounds[p[i]].second);
			}
			ans = max(ans, bounds[i].second - bounds[i].first);
		}
		ans = max(ans, (pa.second - pa.first + 1) / 2);
		int mid = (pa.first + pa.second) / 2;
		cout << ans << endl;
	}
}