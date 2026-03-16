#include <bits/stdc++.h>
using namespace std;
int n, target;
int main(){
    cin >> n >> target;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = 0;
    long long int sum = arr[0];
    while(left < n && right < n){
        while(sum <= target && right < n - 1){
            //cout << left << ' ' << right << ' ' << sum << endl;
            sum = sum - arr[right++] + arr[right];
            if(sum == target){
                cout << ++left << ' ' << ++ right;
                return 0;
            }
        }
        sum = sum - arr[left++] + arr[left];
        if(sum == target){
            cout << ++left << ' ' << ++ right;
            return 0;
        }
        right = left + 1;
    }
    cout << "IMPOSSIBLE";
}