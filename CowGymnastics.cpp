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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, m, x;
    cin >> n >> m;
    int total = 0;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            arr[i][x - 1] = j;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            bool ok = true;
            for(int k = 0; k < n; k++){
                if(arr[k][i] <= arr[k][j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                total++;
            }
            ok = true;
            for(int k = 0; k < n; k++){
                if(arr[k][i] >= arr[k][j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                total++;
            }
        }
    }
    cout << total;
}