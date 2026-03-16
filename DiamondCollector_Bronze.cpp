#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <string>
using namespace std;
int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, m, maxi = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        int base = arr[i];
        int num = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[j] - base <= m){
                num++;
            }else{
                break;
            }
        }
        maxi = max(maxi, num);
    }
    cout << maxi;
}