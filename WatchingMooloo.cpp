#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, k, total = 0;
    cin >> n >> k;
    vector<long long int> arr(n);
    vector<long long int> diff(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i == 0){
            total += k + 1;
            continue;
        }
        diff[i] = arr[i] - arr[i - 1];
        total += min(diff[i], k + 1);
    }
    cout << total;
}