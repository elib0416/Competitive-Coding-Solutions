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
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout); 
    vector<vector<char>> arr(10, vector<char>(10));
    int x, y, ex, ey, rx, ry;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'B'){
                ex = i;
                ey = j;
            }else if(arr[i][j] == 'L'){
                x = i;
                y = j;
            }else if(arr[i][j] == 'R'){
                rx = i;
                ry = j;
            }
        }
    }
    int dis = abs(ex - x) + abs(ey - y) - 1;
    if(ex == x && x == rx){
        if((ry > y && ry < ey) || (ry < y && ry > ey)){
            dis += 2;
        }
    }else if(ey == y && y == ry){
        if((rx > x && rx < ex) || (rx < x && rx > ex)){
            dis += 2;
        }
    }
    cout << dis;
}