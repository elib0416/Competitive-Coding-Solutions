#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <set>
using namespace std;
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n, x, y, z, maxarea = 0;;
    cin >> n;
    map<int, vector<int>> hasx, hasy;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        hasx[arr[i].first].push_back(i);
        hasy[arr[i].second].push_back(i);
    }
    for(int i = 0 ; i < n; i++){
        x = arr[i].first;
        y = arr[i].second;
        for(int newindex : hasx[x]){
            for(int newindex2 : hasy[y]){
                if(newindex == newindex2){
                    continue;
                }
                maxarea = max(maxarea, abs(arr[newindex].second - y) * abs(arr[newindex2].first - x));
            }
        }
    }
    cout << maxarea;
}