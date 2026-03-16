#include <bits/stdc++.h>
using namespace std;
const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};
char arr[1001][1001];
bool visited[10001][1001] = {{false}};
int a, p, n;
bool compare(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    } 
}
void dfs(int x, int y){
    visited[x][y] = true;
    a++;
    for(int i = 0; i < 4; i++){
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if(nx >= 0 && nx <= n && ny >= 0 && ny <= n && !visited[nx][ny] && arr[nx][ny] == '#'){
            dfs(nx, ny);
        }else if(!(nx >= 0 && nx <= n && ny >= 0 && ny <= n) || arr[nx][ny] != '#'){
            p++;
        }
    }
}
int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    vector<pair<int, int>> blobs;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && arr[i][j] == '#'){
                a = 0;
                p = 0;
                dfs(i, j);
                blobs.push_back({a, p});
            }
        }
    }
    sort(blobs.begin(), blobs.end(), compare);
    cout << blobs[0].first << ' ' << blobs[0].second;
}