#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> coins(n);
	for(int i = 0; i < n; i++){
	    cin >> coins[i];
	}
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int x = 0; x <= m; x++){
            if(x - coins[i] >= 0){
                dp[x] += dp[x - coins[i]];
                dp[x] %= mod;
            }
        }
    }
    cout << dp[m];
}