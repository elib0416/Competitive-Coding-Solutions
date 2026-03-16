#include <bits/stdc++.h>
using namespace std;
int mod;
bool compare(int& a, int& b){
    return a % mod > b % mod;
}
int main(){
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k, maxiberries;
    cin >> n >> k;
    vector<int> berries(n);
    for(int i = 0; i < n; i++){
        cin >> berries[i];
        maxiberries = max(maxiberries, berries[i]);
    }
    int Bmax = 0, cur = 0, amt = 0;
    for(int i = 1; i <= maxiberries; i++){
        amt = 0;
        cur = 0;
        for(int j = 0; j < n; j++){
            amt += berries[j] / i;
        }
        if(amt < k / 2){
            continue;
        }else if(amt >= k){
            Bmax = max(Bmax, k / 2 * i);
            continue;
        }
        cur = (amt - k / 2) * i;
        mod = i;
        sort(berries.begin(), berries.end(), compare);
        for(int j = 0; j < n && j + amt < k; j++){
            cur += berries[j] % i;
            cout << berries[j] % i;
        }
        Bmax = max(Bmax, cur);
    }
    cout << Bmax;
}