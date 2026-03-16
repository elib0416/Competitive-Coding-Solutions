#include <bits/stdc++.h>
using namespace std;
int dp[509][509];
int ndp[509][509];
const int bignumberbecauseitisaverybignumberwhichis1e9plus7 = 1e9 + 7;
int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    if(grid[0][0] == grid[n - 1][n - 1]){
        dp[0][n - 1] = 1;
    }else{
        cout << 0 << endl;
        return 0;
    }
    for(int k = 1; k < n; k++){
        memset(ndp, 0, sizeof(ndp));
        for(int i = 0; i <= k; i++){
            for(int j = n - 1; j >= n - 1 - k; j--){
                int c1 = k - i;
                int c2 = (n - 1) - (k - (n - 1 - j));
                if(c1 < 0 || c1 >= n || c2 < 0 || c2 >= n){
                    continue;
                }
                if(grid[i][c1] != grid[j][c2]){
                    continue;
                }
                long long val = dp[i][j];
                if(i > 0){
                    val += dp[i - 1][j]; 
                } 
                if(j < n - 1){
                    val += dp[i][j + 1];
                } 
                if(i > 0 && j < n - 1){
                    val += dp[i - 1][j + 1];
                }
                ndp[i][j] = val % bignumberbecauseitisaverybignumberwhichis1e9plus7;
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[i][i]) % bignumberbecauseitisaverybignumberwhichis1e9plus7;
    }
    cout << ans << endl;
}
