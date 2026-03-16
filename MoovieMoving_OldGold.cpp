#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int>> schedule;
vector<vector<vector<int>>> next_show;
vector<int> length;
vector<pair<int, int>> dp;
int turnto1(int n, int k){
    return (n | (1 << k));
}
int ftw(int t, int m){
	auto it = upper_bound(schedule[m].begin(), schedule[m].end(), t);
	if (it == schedule[m].begin()){
	    return -1;
	}
	int start = *(it - 1);
	if (start + length[m] < t || start > t){
	    return -1;
	}
	return (it - 1) - schedule[m].begin();
}
int main(){
	ifstream cin("movie.in");
	ofstream cout("movie.out");
	cin >> n >> l;
	length.resize(n);
	schedule.resize(n);
	next_show.resize(n, vector<vector<int>>(n, vector<int>(0, -1)));
	for (int i = 0; i < n; i++){
		int t, v;
		cin >> t >> v;
		length[i] = t;
		int a;
		while (v){
			cin >> a;
			schedule[i].push_back(a);
			v--;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j){
			    continue;
			} 
			for (int ti = 0; ti < schedule[i].size(); ti++){
				next_show[i][j].push_back(ftw(schedule[i][ti] + length[i], j));
			}
		}
	}
	dp.resize(1 << n, {-1, -1});
	int ans = n + 1;
	dp[0] = {0, 0};
	for (int i = 0; i < 1 << n; i++){
		if (dp[i].first == -1){
		    continue;
		}
		for (int j = 0; j < n; j++){
			if((i & (1 << j))>> j){
			    continue;
			} 
			int subs = turnto1(i, j);
			int x;
			if (i == 0){
				x = schedule[j][0] == 0 ? 0 : -1;
			} else {
				x = next_show[dp[i].first][j][dp[i].second];
			}
			if (x != -1){
				if (dp[subs].first == -1 || schedule[dp[subs].first][dp[subs].second] + length[dp[subs].first] < schedule[j][x] + length[j]){
					dp[subs] = {j, x};
				}
				if (schedule[dp[subs].first][dp[subs].second] + length[dp[subs].first] >= l){
					ans = min(ans, __builtin_popcount(subs));
				}
			}
		}
	}
    if(ans == n + 1){
        cout << -1;
    }else{
        cout << ans;
    }
}