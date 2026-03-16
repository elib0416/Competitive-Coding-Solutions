#include <bits/stdc++.h>
using namespace std;
int n, target;
int main(){
    cin >> n >> target;
    vector<int> arr(n, 0);
    map<int, vector<int>> ma;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ma[arr[i]].push_back(i);
    }
    sort(arr.begin(), arr.end());
    /*for(int i = 0; i < n; i ++){
        cout << arr[i] << ' ';
    }
    cout << endl;*/
    int left = 0;
    int right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum < target){
            left++;
        }else if(sum > target){
            right--;
        }else{
            if(arr[left] != arr[right]){
                cout << ++ma[arr[left]][0] << ' ' << ++ma[arr[right]][0];
            }else{
                cout << ++ma[arr[left]][0] << ' ' << ++ma[arr[right]][1];
            }
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}