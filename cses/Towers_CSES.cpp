#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> towers;
    for(int i = 0; i < n; i++){
        int pos = upper_bound(towers.begin(), towers.end(), arr[i]) - towers.begin();
        if(pos == towers.size()){
            towers.push_back(arr[i]);
        }else{
            towers[pos] = arr[i];
        }
    }
    cout << towers.size();
}