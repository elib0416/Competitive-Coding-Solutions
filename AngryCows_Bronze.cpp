#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int explode(int start, int dir){
    int r = 1;
    int prev = start;
    while(true){
        int next = prev;
        while(next + dir >= 0 && next + dir < n && abs(arr[next + dir] - arr[prev]) <= r){
            next += dir;
        }
        if(next == prev){
            break;
        }
        prev = next;
        r++;
    }
    return abs(prev - start);
}
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, explode(i, 1) + explode(i, -1) + 1);
    }
    cout << maxi;
}