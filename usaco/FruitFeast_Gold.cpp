#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
	int n, a, b, best = 0;
	cin >> n >> a >> b;
	vector<int> dp(n + 1);
	dp[0] = 1;
	const int randommod = 1e9 + 7;
	for(int i = 0; i <= n; i++){
	    if(i + a <= n){
	        dp[i + a] += dp[i];
	        dp[i + a] %= randommod;
	    }
	    if(i + b <= n){
	        dp[i + b] += dp[i];
	        dp[i + b] %= randommod;
	    }
	}
	for(int i = 0; i <= n / 2; i++){
	    dp[i] = dp[2 * i] + dp[2 * i + 1];
	}
	for(int i = 0; i <= n; i++){
	    if(i + a <= n){
	        dp[i + a] += dp[i];
	        dp[i + a] %= randommod;
	    }
	    if(i + b <= n){
	        dp[i + b] += dp[i];
	        dp[i + b] %= randommod;
	    }
	}
	for(int i = n; i >= 0; i--){
	    if(dp[i] > 0){
	        best = i;
	        break;
	    }
	}
	cout << best;
}