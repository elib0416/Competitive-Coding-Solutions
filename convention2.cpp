#include <bits/stdc++.h>
using namespace std;
bool compare(const array<int, 3> &a, const array<int, 3> &b){
    return a[1] < b[1];
}
int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	int n;
	vector<array<int, 3>> cows;
	cin >> n;
	for (int seniority = 0; seniority < n; seniority++) {
		int start, duration;
		cin >> start >> duration;
		cows.push_back({seniority, start, duration});
	}
	sort(cows.begin(), cows.end(), compare);
	int t = 0;
	int cur_index = 0;
	int max_wait = 0;
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> line;
	while (cur_index < n || !line.empty()) {
		if (cur_index < n && cows[cur_index][1] <= t){
			line.push(cows[cur_index]);
			cur_index++;
		}else if(line.empty()){
			t = cows[cur_index][1] + cows[cur_index][2];
			cur_index++;
		}else{
		    //cout << cur_index << ' ' << max_wait << ' ' << t << endl;
			array<int, 3> nextcow = line.top();
			max_wait = max(max_wait, t - nextcow[1]);
			t += nextcow[2];
			line.pop();
		}
	}
	cout << max_wait;
}