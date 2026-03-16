#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
	int n, m, a;
	cin >> n >> m;
	//cout << n << ' ' << m << ' ';
	vector<int> coins(n);
	for(int i = 0; i < n; i++){
	    cin >> coins[i];
	}
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= m; i++){
	    //cout << i;
	    for(int x : coins){
	        if(i - x >= 0){
	            dp[i] += dp[i - x];
	            dp[i] = dp[i] % mod;
	        }
	    }
	}
	cout << dp[m];
}