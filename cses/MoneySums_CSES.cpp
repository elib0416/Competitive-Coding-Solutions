#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> dp(100001);
    dp[0] = 1;
    for(int x : arr){
        for(int i = 100000; i >= x; i--){
            dp[i] += dp[i - x];
        }
    }
    set<int> good;
    for(int i = 1; i < 100001; i++){
        if(dp[i]){
            good.insert(i);
        }
    }
    cout << good.size() << endl;
    for(int x : good){
        cout << x << ' ';
    }
}