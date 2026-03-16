#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x, y;
    vector<int> arr;
    vector<int> diff(2 * n);
    map<int, int> isend;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        arr.push_back(x);
        arr.push_back(y);
        isend[y]++;
    }
    sort(arr.begin(), arr.end());
    /*for(auto x : arr){
        cout << x << ' ';
    }
    cout << endl;*/
    for(int i = 0; i < 2 * n; i++){
         if(isend[arr[i]] == 0){
             diff[i]++;
         }else{
             //cout << arr[i] << '-';
             if(i != 2 * n - 1){
                 diff[i + 1]--;
             }
             isend[arr[i]]--;
         }
    }
    
    int now = 0;
    int maxi = 0;
    for(int i = 0; i < 2 * n; i++){
        now += diff[i];
        maxi = max(now, maxi);
    }
    cout << maxi;
}