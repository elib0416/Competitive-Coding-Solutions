#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> skill(n);
    for(int i = 0; i < n; i++){
        cin >> skill[i];
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        vector<int> pf(k + 1);
        pf[0] = 0;
        //next team is size j
        //pf is the maximum of the next j numbers
        for(int j = 1; j <= min(k, n - i); j++){
            pf[j] = max(pf[j - 1], skill[i + j - 1]);
            dp[i + j] = max(dp[i + j], dp[i] + j * pf[j]);
            //cout << i << ' ' << j << ' ' << pf[j] << endl;
        }
    }
    cout << dp[n];
}