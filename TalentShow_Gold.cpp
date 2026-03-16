#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> dp(250000 + 2, 1e9 + 7);
    vector<int> abovem(250000 + 2, 1e9 + 7);
    dp[0] = 0;
    abovem[0] = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = 250000 - b; j >= 0; j--){
            if(dp[j] == 1e9 + 7){
                continue;
            }
            dp[j + b] = min(dp[j + b], dp[j] + a);
            if(dp[j] + a >= m){
                abovem[j + b] = min(abovem[j + b], dp[j] + a);
            }
        }
    }
    double ans = 0;
    for(int i = 1; i <= 250000; i++){
        if(abovem[i] >= 1e9 + 7){
            continue;
        }
        ans = max(ans, static_cast<double>(static_cast<double>(i) / static_cast<double>(abovem[i])));
    }
    cout << floor(ans * 1000);
}