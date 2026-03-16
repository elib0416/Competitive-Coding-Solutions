#include <bits/stdc++.h>
using namespace std;
long long int dist(pair<long long int, long long int>& A, pair<long long int, long long int>& B){
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}
int main(){
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    long long int n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int>> FJ(n + 1), B(m + 1);
    cin >> FJ[0].first >> FJ[0].second;
    cin >> B[0].first >> B[0].second;
    string f, b;
    cin >> f;
    cin >> b;
    for(long long int i = 0; i < n; i++){
        if(f[i] == 'N'){
            FJ[i + 1] = {FJ[i].first, FJ[i].second + 1};
        }else if(f[i] == 'S'){
            FJ[i + 1] = {FJ[i].first, FJ[i].second - 1};
        }else if(f[i] == 'W'){
            FJ[i + 1] = {FJ[i].first - 1, FJ[i].second};
        }else{
            FJ[i + 1] = {FJ[i].first + 1, FJ[i].second};
        }
    }
    for(long long int i = 0; i < m; i++){
        if(b[i] == 'N'){
            B[i + 1] = {B[i].first, B[i].second + 1};
        }else if(b[i] == 'S'){
            B[i + 1] = {B[i].first, B[i].second - 1};
        }else if(b[i] == 'W'){
            B[i + 1] = {B[i].first - 1, B[i].second};
        }else{
            B[i + 1] = {B[i].first + 1, B[i].second};
        }
    }
    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, 1e9 + 7));
    dp[0][0] = 0;
    for(long long int i = 0; i <= n; i++){
        for(long long int j = 0; j <= m; j++){
            if(dp[i][j] == 1e9 + 7){
                continue;
            }
            if(i != n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(FJ[i + 1], B[j]));
            }
            if(j != m){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(FJ[i], B[j + 1]));
            }
            if(i != n && j != m){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(FJ[i + 1], B[j + 1]));
            }
        }
    }
    cout << dp[n][m];
}