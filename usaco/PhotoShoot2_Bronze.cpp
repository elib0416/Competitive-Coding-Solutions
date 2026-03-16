#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n), arr1(n);
    map<int, int> convert;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        //cout << arr[i] << ' ';
        convert[arr[i]] = i;
    }
    //cout << endl;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        //cout << arr1[i] << ' ';
    }
    //cout << endl;
    int i = 0, j = 0;
    vector<bool> seen(n, false);
    int number = 0;
    while(i < n && j < n){
        if(seen[i]){
            i++;
        }else if(arr1[j] == arr[i]){
            seen[convert[arr1[j]]] = true;
            i++;
            j++;
            number++;
        }else{
            seen[convert[arr1[j]]] = true;
            j++;
        }
    }
    cout << n - number << endl;
}