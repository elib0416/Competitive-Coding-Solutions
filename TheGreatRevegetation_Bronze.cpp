#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m;
    map<int, vector<int>> fav;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        fav[a].push_back(b);
        fav[b].push_back(a);
    }
    vector<int> arr(n);
    for(int i = 1; i <= n; i++){
        int num = 1;
        vector<bool> canvisit(5);
        for(int x : fav[i]){
            if(x < i){
                canvisit[arr[x]] = true;
            }
        }
        for(int j = 1; j <= 4; j++){
            if(!canvisit[j]){
                arr[i] = j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i];
    }
}