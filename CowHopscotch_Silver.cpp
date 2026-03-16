#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(dp[i][j] == 0){
                continue;
            }
            for(int ii = i + 1; ii < n; ii++){
                for(int jj = j + 1; jj < m; jj++){
                    if(arr[i][j] != arr[ii][jj]){
                        //cout << i << ' ' << j << ' ' << ii << ' ' << jj << endl;
                        dp[ii][jj] += (dp[i][j]) % 1000000007;
                        dp[ii][jj] = ((dp[ii][jj] % 1000000007) + 1000000007) % 1000000007;
                    }
                }
            }
        }
    }
    cout << dp[n - 1][m - 1];
}