#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout); 
    int n, a, b, c, mx = 0;
    cin >> n;
    vector<int> arr(2000);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        for(int j = a; j < b; j++){
            arr[j] += c;
            mx = max(mx, arr[j]);
        }
    }
    cout << mx;
}