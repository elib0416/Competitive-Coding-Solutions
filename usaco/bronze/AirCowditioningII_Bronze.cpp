#include <bits/stdc++.h>
using namespace std;
struct cow{
    int a, b, c;
};
struct ac{
    int a, b, c, d;
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> stalls(103);
    vector<ac> acs(m);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++){
            stalls[j] = max(stalls[j], c);
        }
    }
    for(int i = 0; i < m; i++){
        cin >> acs[i].a >> acs[i].b >> acs[i].d >> acs[i].c;
    }
    int mini = 1e9 + 7;
    for(int i = 0; i < (1 << m); i++){
        vector<int> arr(103);
        int cost = 0;
        for(int j = 0; j < m; j++){
            if((i >> j) & 1){
                cost += acs[j].c;
                for(int k = acs[j].a; k <= acs[j].b; k++){
                    arr[k] += acs[j].d;
                }
            }
        }
        bool good = true;
        for(int j = 0; j < 103; j++){
            if(arr[j] < stalls[j]){
                good = false;
                break;
            }
        }
        if(good){
            mini = min(mini, cost);
        }
    }
    cout << mini;
}