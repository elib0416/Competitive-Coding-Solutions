#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n, k, total = 0;
    cin >> n;
    vector<int> arr;
    vector<int> other_cow;
    vector<bool> isinother_cow(2 * n + 1);
    for(int i = 0; i < n; i++){
        cin >> k;
        other_cow.push_back(k);
        isinother_cow[k] = true;
        //arr.erase(remove(arr.begin(), arr.end(), k));
    }
    for(int i = 1; i <= 2 * n; i++){
        if(!isinother_cow[i]){
            arr.push_back(i);
        }
    }
    //sort(arr.begin(), arr.end());
    sort(other_cow.begin(), other_cow.end());
    /*for(auto x : arr){
        cout << x << ' ';
    }
    cout << endl;
    for(auto x : other_cow){
        cout << x << ' ';
    }
    cout << endl;*/
    int index;
    for(auto x : other_cow){
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if(it != arr.end()){
            //cout << *it << ' ';
            //cout << x << ' ' << arr[index] << endl;
            total++;
            arr.erase(it);
        }
    }
    cout << total;
}