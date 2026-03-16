#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c, a, b;
    cin >> n >> m >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int, vector<int>> paths;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
    }
    vector<vector<long long int>> dp(1002, vector<long long int>(n, -1));
    dp[0][0] = 0;
    for(int t = 0; t < 1001; t++){
        for(int city = 0; city < n; city++){
            if(dp[t][city] == -1){
                continue;
            }
            for(int x : paths[city]){
                dp[t + 1][x] = max(dp[t + 1][x], dp[t][city] + arr[x]);
            }
        }
    }
    
    long long int maximum = 0;
    for(int i = 0; i < 1002; i++){
        maximum = max(maximum, dp[i][0] - c * i * i);
    }
    cout << maximum;
    return 0;
}