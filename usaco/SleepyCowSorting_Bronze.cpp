#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> start(n);
    for(int i = 0; i < n; i++){
        cin >> start[i];
    }
    int num = n - 1;
    for(int i = n - 2; i >= 0; i--){
        if(start[i + 1] > start[i]){
            num = i;
        }else{
            break;
        }
    }
    cout << num;
}