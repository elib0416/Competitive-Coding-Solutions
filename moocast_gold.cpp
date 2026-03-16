#include <bits/stdc++.h>
using namespace std;
struct cow {
    long long int x, y;
};
long long int square(long long int a){
    return a * a;
}
void dfs(int index, vector<vector<int>>& arr, vector<bool>& visited){
    visited[index] = true;
    for(int neighbor : arr[index]){
        if (!visited[neighbor]){
            dfs(neighbor, arr, visited);
        }
    }
}
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    long long int n;
    cin >> n;
    vector<cow> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i].x >> cows[i].y;
    }
    long long int l = 0, r = LLONG_MAX, ans = r;
    while(l <= r){
        long long int mid = (l + r)/ 2;
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == j){
                    continue;
                }
                long long int dist = square(cows[i].x - cows[j].x)+ square(cows[i].y - cows[j].y);
                if (dist <= mid){
                    arr[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        dfs(0, arr, visited);
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ok = false;
                break;
            }
        }
        if (ok){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
