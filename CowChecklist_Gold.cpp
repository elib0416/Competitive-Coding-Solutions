#include <bits/stdc++.h>
using namespace std;
long long int sq(long long int x){
    return x * x;
}
int main(){
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    long long int n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int>> H(n + 1), G(m + 1);
    for(long long int i = 1; i <= n; i++){
        cin >> H[i].first >> H[i].second;
    }
    for(long long int i = 1; i <= m; i++){
        cin >> G[i].first >> G[i].second;
    }
    vector<vector<vector<long long int>>> dp(n + 1, vector<vector<long long int>>(m + 1, vector<long long int>(2, LLONG_MAX / 2)));
    dp[1][0][0] = 0;
    for(long long int i = 1; i <= n; i++){
        for(long long int j = 0; j <= m; j++){
            for(long long int k = 0; k < 2; k++){
                if(dp[i][j][k] == LLONG_MAX / 2){
                    continue;
                }
                if(i != n){
                    if(k == 0){
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + sq(H[i + 1].first - H[i].first) + sq(H[i + 1].second - H[i].second));
                    }else{
                        dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + sq(H[i + 1].first - G[j].first) + sq(H[i + 1].second - G[j].second));
                    }
                }
                if(j != m){
                    if(k == 0){
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + sq(G[j + 1].first - H[i].first) + sq(G[j + 1].second - H[i].second));
                    }else if(j > 0){
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + sq(G[j + 1].first - G[j].first) + sq(G[j + 1].second - G[j].second));
                    }
                }
            }
        }
    }
    cout << dp[n][m][0];
}