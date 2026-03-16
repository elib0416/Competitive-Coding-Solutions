#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int med;
    if(n % 2 == 0){
        med = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }else{
        med = arr[n / 2];
    }
    long long int cost = 0;
    for(auto x : arr){
        cost += abs(med - x);
    }
    cout << cost;
}