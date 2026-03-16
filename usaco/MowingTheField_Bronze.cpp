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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout); 
    int n, maxi = 1e9;
    char c;
    int a;
    cin >> n;
    vector<vector<int>> arr(2001, vector<int>(2001, -1));
    arr[1000][1000] = 0;
    int t = 0;
    int x = 1000, y = 1000;
    for(int i = 0; i < n; i++){
        cin >> c >> a;
        int next = t + a;
        if(c == 'N'){
            while(t < next){
                t++;
                y++;
                if(arr[x][y] != -1){
                    maxi = min(maxi, t - arr[x][y]);
                }
                arr[x][y] = t;
            }
        }else if(c == 'S'){
            while(t < next){
                t++;
                y--;
                if(arr[x][y] != -1){
                    maxi = min(maxi, t - arr[x][y]);
                    arr[x][y] = t;
                }
                arr[x][y] = t;
            }
        }else if(c == 'E'){
            while(t < next){
                t++;
                x++;
                if(arr[x][y] != -1){
                    maxi = min(maxi, t - arr[x][y]);
                    arr[x][y] = t;
                }
                arr[x][y] = t;
            }
        }else{
            while(t < next){
                t++;
                x--;
                if(arr[x][y] != -1){
                    maxi = min(maxi, t - arr[x][y]);
                    arr[x][y] = t;
                }
                arr[x][y] = t;
            }
        }
    }
    if(maxi == 1e9){
        cout << -1;
        return 0;
    }
    cout << maxi;
}