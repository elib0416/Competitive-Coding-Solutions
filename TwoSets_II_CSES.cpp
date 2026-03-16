#include <bits/stdc++.h> 
using namespace std;
int main(){
    const long long int mod = 2e9 + 14;
    long long int n;
    cin >> n;
    if(((n * (n + 1)) / 2) % 2 == 1){
        cout << 0;
        return 0;
    }
    const long long int target = (n * (n + 1)) / 4;
    vector<long long int> dp(target + 1);
    dp[0] = 1;
    for(long long int i = 1; i <= n; i++){
        for(long long int j = target - i; j >= 0; j--){
            dp[j + i] += dp[j];
            dp[j + i] %= mod;
            //cout << j + i << ' ' << j << ' ' << dp[j + i] << endl;
        }
    }
    cout << dp[target] / 2;
}