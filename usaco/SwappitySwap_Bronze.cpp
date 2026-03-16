#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k, a, b, c, d, num = 1;
    cin >> n >> k;
    cin >> a >> b;
    cin >> c >> d;
    //cout << k << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
    vector<int> arr(n);
    vector<int> arr1(n);
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
        arr1[i] = i + 1;
    }
    reverse(arr1.begin() + a - 1, arr1.begin() + b);
    reverse(arr1.begin() + c - 1, arr1.begin() + d);
    while(arr1 != arr){
        num++;
        reverse(arr1.begin() + a - 1, arr1.begin() + b);
        reverse(arr1.begin() + c - 1, arr1.begin() + d);
    }
    k = k % num;
    for(int i = 0; i < k; i++){
        reverse(arr.begin() + a - 1, arr.begin() + b);
        reverse(arr.begin() + c - 1, arr.begin() + d);
    }
    for(int x : arr){
        cout << x << endl;
    }
}