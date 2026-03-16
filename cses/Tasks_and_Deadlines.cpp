#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> arr(n);
    for(long long int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    long long int reward = 0;
    long long int t = 0;
    for(long long int i = 0; i < n; i++){
        t += arr[i].first;
        reward += arr[i].second - t;
    }
    cout << reward;
}