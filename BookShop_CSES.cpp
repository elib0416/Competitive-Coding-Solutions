#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> price(n);
	vector<int> page(n);
	for(int i = 0; i < n; i++){
	    cin >> price[i];
	}
	for(int i = 0; i < n; i++){
	    cin >> page[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
	    int cost = price[i - 1];
	    int numpage = page[i - 1];
	    for(int j = 1; j <= m; j++){
	        dp[i][j] = dp[i - 1][j];
	        if(cost <= j){
	            dp[i][j] = max(dp[i][j], dp[i - 1][j - cost] + numpage);
	        }
	    }
	}
	cout << dp[n][m];
}