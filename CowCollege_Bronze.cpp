#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<long long int>());
    long long int mAx = -1;
    long long int cur = -1;
    for(int i = 1; i <= n; i++){
        long long int x = i * arr[i - 1];
        if(x >= mAx){
            cur = arr[i - 1];
            mAx = x;
        }
    }
    cout << mAx << ' ' << cur;
}