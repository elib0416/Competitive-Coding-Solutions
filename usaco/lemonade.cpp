#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    long long int n;
    cin >> n;
    vector<long long int> cows(n);
    for(long long int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end(), greater<long long int>());
    long long int cows_infront = 0;
    for(long long int i = 0; i < n; i++){
        if(cows[i] >= cows_infront){
            cows_infront++;
        }
    }
    cout << cows_infront;
}