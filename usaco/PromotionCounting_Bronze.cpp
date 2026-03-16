#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    vector<int> arr(4), arr1(4), prom(3);
    for(int i = 0; i < 4; i++){
        cin >> arr[i] >> arr1[i];
        //cout << arr[i] << ' ' << arr1[i] << endl;
    }
    for(int i = 3; i >= 1; i--){
        prom[i - 1] = arr1[i] - arr[i];
        //cout << prom[i - 1] << endl;
        arr1[i - 1] += prom[i - 1];
    }
    for(int x : prom){
        cout << x << endl;
    }
}