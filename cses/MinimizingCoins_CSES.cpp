#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> coins(n);
	for(int i = 0; i < n; i++){
	    cin >> coins[i];
	}
	vector<int> dp(m + 1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= m; i++){
	    for(int x : coins){
	        if(i - x >= 0){
	            dp[i] = min(dp[i], dp[i - x] + 1);
	        }
	    }
	}
	if(dp[m] == 1e9){
	    cout << -1;
	}else{
	    cout << dp[m];
	}
}