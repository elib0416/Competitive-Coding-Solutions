#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, -1)));
    dp[0][0][0] = 1;
    for(int k = 0; k < c; k++){
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                if(dp[i][j][k] == -1){
                    continue;
                }
                dp[0][j][k + 1] = 1;
                dp[i][0][k + 1] = 1;
                dp[a][j][k + 1] = 1;
                dp[i][b][k + 1] = 1;
                dp[i + min(a - i, j)][j - min(a - i, j)][k + 1] = 1;
                dp[i - min(b - j, i)][j + min(b - j, i)][k + 1] = 1;
            }
        } 
    }
    int ans = 1e9 + 7;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(dp[i][j][c] == 1){
                ans = min(ans, abs(d - i - j));
            }
        }
    }
    cout << ans;
}