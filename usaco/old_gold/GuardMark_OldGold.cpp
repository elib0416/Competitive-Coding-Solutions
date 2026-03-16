#include <bits/stdc++.h>
using namespace std;
long long m;
struct pos {
    long long height, saf;
};
int main(){
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    int n;
    cin >> n >> m;
    vector<long long> cows(n), strength(n), weight(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i] >> weight[i] >> strength[i];
    }
    vector<pos> dp(1 << n, {0, -1});
    dp[0] = {0, 1000000007};
    for(int i = 0; i < (1 << n); i++){
        if(dp[i].saf < 0){
            continue;
        }
        for(int j = 0; j < n; j++){
            if(!((i >> j) & 1)){
                pos newn = {dp[i].height + cows[j], min(dp[i].saf - weight[j], strength[j])};
                if(newn.saf >= 0 && newn.saf > dp[i | (1 << j)].saf){
                    dp[i | (1 << j)] = newn;
                }
            }
        }
    }
    long long ans = -1;
    for(int i = 0; i < (1 << n); i++){
        if(dp[i].height >= m){
            ans = max(ans, dp[i].saf);
        }
    }
    if(ans >= 0){
        cout << ans;
    }else{
        cout << "Mark is too tall";
    } 
}
