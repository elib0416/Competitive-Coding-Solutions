#include <bits/stdc++.h>
using namespace std;
struct Cow {
	int l, r;
};
bool operator<(const Cow &a, const Cow &b) {
    return a.l < b.l;
}
int main() {
	freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vector<Cow> cows(n);
	for (int i = 0; i < n; i++){
	    cin >> cows[i].l >> cows[i].r;
	}
	sort(cows.begin(), cows.end());
	int t = 0;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (cows[i].r > r) {
			l = max(r, cows[i].l);
			t += cows[i].r - l;
			r = cows[i].r;
		}
	}
	Cow last;
	last.l = cows[n - 1].r;
	cows.push_back(last);
	int minT = t;
	r = 0;
	for (int i = 0; i < n; i++) {
		int timeAlone = min(cows[i + 1].l, cows[i].r) - max(cows[i].l, r);
		minT = min(minT, timeAlone);
		//cout << "cow " << i << " has spent " << timeAlone << " units of time alone";
		//cout << ". The current minimum time alone is " << minT << endl;
		r = max(r, cows[i].r);
	}
	cout << t - max(minT, 0) << endl;
}