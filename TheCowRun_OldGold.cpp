#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    cin >> n;
    vector<long long int> cows(n);
    for(long long int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    // dp[i][j][0] -> min cost to halter cows from i to j, ending at i
    // dp[i][j][1] -> min cost to halter cows from i to j, ending at j
    vector<vector<vector<long long int>>> dp(n + 1, vector<vector<long long int>>(n + 1, vector<long long int>(2, INT64_MAX)));
   
    // Base cases for a single cow
    for(long long int i = 0; i < n; i++){
        dp[i][i][0] = abs(cows[i]) * n;
        dp[i][i][1] = abs(cows[i]) * n;
    }

    // Dynamic programming loop
    for(long long int len = 2; len <= n; len++){
        for(long long int i = 0; i <= n - len; i++){
            long long int j = i + len - 1;
            long long int remaining_cows = n - len;

            // Transition to range [i, j] ending at i
            // Came from [i+1, j] ending at i+1
            dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + abs(cows[i + 1] - cows[i]) * remaining_cows);
            // Came from [i+1, j] ending at j
            dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + abs(cows[j] - cows[i]) * remaining_cows);

            // Transition to range [i, j] ending at j
            // Came from [i, j-1] ending at i
            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + abs(cows[i] - cows[j]) * remaining_cows);
            // Came from [i, j-1] ending at j-1
            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + abs(cows[j - 1] - cows[j]) * remaining_cows);
        }
    }
   
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}