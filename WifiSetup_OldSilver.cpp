#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    long double x = static_cast<long double>(static_cast<long double>(a) / 1.0);
    long double y = static_cast<long double>(static_cast<long double>(b) / 1.0);
    vector<int> cows(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    vector<long double> dp(n + 1, static_cast<long double>(1e9 + 7));
    dp[0] = 0.0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n - i; j++){
            dp[i + j] = min(dp[i + j], dp[i] + x + y * static_cast<long double>(static_cast<long double>(cows[i + j] - cows[i + 1]) / 2.0));
        }
    }
    int z = floor(dp[n]);
    double leftover = dp[n] - z;
    if(leftover != 0.0 && leftover != 0){
        cout << z << ".5";
    }else{
        cout << z;
    }
}