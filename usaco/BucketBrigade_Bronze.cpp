#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
using namespace std;
const int dirx[4] = {0, 0, -1, 1};
const int diry[4] = {1, -1, 0, 0};
struct node{
    int x, y, depth;
};
int main(){
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout); 
    const int n = 10;
    int x, y, ex, ey;
    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool>(n));    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'B'){
                ex = i;
                ey = j;
            }else if(arr[i][j] == 'L'){
                x = i;
                y = j;
            }
        }
    }
    queue<node> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            int nx = current.x + dirx[i];
            int ny = current.y + diry[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(!(!visited[nx][ny] && arr[nx][ny] != 'R')){
                    continue;
                }
                if(arr[nx][ny] == 'B'){
                    cout << current.depth;
                    return 0;
                }
                q.push({nx, ny, current.depth + 1});
                visited[nx][ny] = true;
            }
        }
    }
    cout << 0;
}