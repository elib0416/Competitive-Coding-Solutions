#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long int mod = 1e9 + 7;
    long long int n, m, a;
    cin >> n >> m;
    vector<long long int> arr(n);
    for(long long int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<long long int>> dp(n, vector<long long int>(m));
    for(long long int i = 0; i < n; i++){
        if(i == 0){
            if(arr[0] == 0){
                for(long long int j = 0; j < m; j++){
                    dp[i][j] = 1;
                }
            }else{
                dp[i][arr[0] - 1] = 1;
            }
            continue;
        }
        if(arr[i] == 0){
            for(long long int j = 0; j < m; j++){
                for(long long int k = -1; k < 2; k++){
                    if(j + k >= 0 && j + k < m){
                        dp[i][j] += dp[i - 1][j + k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }else{
            for(long long int k = -1; k < 2; k++){
                if(arr[i] - 1 + k >= 0 && arr[i] - 1 + k < m){
                    dp[i][arr[i] - 1] += dp[i - 1][arr[i] - 1 + k];
                    dp[i][arr[i] - 1] %= mod;
                }
            }
        }
    }
    /*for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < m; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    long long int sum = 0;
    for(long long int i = 0; i < m; i++){
        sum += dp[n - 1][i];
        sum %= mod;
    }
    cout << sum;
}