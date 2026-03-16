#include <bits/stdc++.h>
using namespace std;
const int mx = 200005;
int arr[mx];
int ans[mx];
int main(){
    int n, k, t;
    cin >> n >> k >> t;
    for(int i = 1; i <= k; i++){
        cin >> arr[i];
    }
    arr[k + 1] = n;
    for(int i = 1; i <= k; i++){
        for(int j = arr[i]; j < arr[i+1]; j++){ 
            int current_shift = j - arr[i]; 
            int new_shift = current_shift - t;
            int diff = arr[i + 1] - arr[i];
            new_shift = (new_shift % diff + diff) % diff;
            ans[(arr[i] + new_shift + t) % n] = j;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i + 1 < n){
            cout << " ";
        }
    }
}