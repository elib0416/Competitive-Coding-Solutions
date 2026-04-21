//This code was implemented by me, with the assistance of my instructor Kyle Fu's pseudocode in Alphastar's CC41F-3: USACO Gold - Part 3
#include <bits/stdc++.h>
using namespace std;
struct game{
    int cost, value;
};
int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> consolecost(n);
    vector<vector<game>> games(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> consolecost[i] >> x;
        for(int j = 0; j < x; j++){
            int a, b;
            cin >> a >> b;
            games[i].push_back({a, b});
        }
    }
    vector<int> dp(m + 3);
    for(int k = 0; k < n; k++){
        vector<int> dp1(m + 3, -1e9);
        for(int i = consolecost[k]; i <= m; i++){
            dp1[i] = dp[i - consolecost[k]];
        }
        for(game g : games[k]){
            for(int i = m; i >= g.cost; i--){
                dp1[i] = max(dp1[i], dp1[i - g.cost] + g.value);
            }
        }
        for(int i = 0; i <= m; i++){
            dp[i] = max(dp[i], dp1[i]);
        }
        
    }
    int ans = 0;
    for(int i = 0; i <= m; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}