#include <bits/stdc++.h>
using namespace std;
int dp[100003][25][3];
int moves[100003];
int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	char a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a == 'H'){
		    moves[i] = 0;
		}
		if(a == 'P'){
		    moves[i] = 1;
		}
		if(a == 'S'){
		    moves[i] = 2;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			for(int l = 0; l < 3; l++){
				if(l == moves[i]){
				    dp[i][j][l]++;
				}
				dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][l]);
				dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][l]);
				dp[i + 1][j + 1][2] = max(dp[i + 1][j + 1][2], dp[i][j][l]);
				dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; i++){
	    ans = max(ans, dp[n - 1][k][i]);
	}
	cout << ans << endl;
}