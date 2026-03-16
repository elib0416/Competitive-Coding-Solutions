#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<string, string>> P;
	for (int i = 0; i < n; i++) {
		string city, state;
		cin >> city >> state;
		city = city.substr(0, 2);
		P.push_back({city, state});
	}
	map<string, int> need;
	long long total = 0;
	for(auto& [ci, st] : P) {
		if (ci != st){
		    total += need[st + ci];
		}
		need[ci + st]++;
	}
	cout << total << endl;
}