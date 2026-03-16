#include <bits/stdc++.h>
using namespace std;
const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};
int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, vector<pair<int, int>>> switches;
    vector<vector<bool>> lit(n, vector<bool>(n, false));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[{x - 1, y - 1}].push_back({a - 1, b - 1});
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    lit[0][0] = true;
    visited[0][0] = true;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (auto& [a, b] : switches[{x, y}]){
            if (!lit[a][b]){
                lit[a][b] = true;
                for (int i = 0; i < 4; i++){
                    int na = a + dirx[i];
                    int nb = b + diry[i];
                    if (na >= 0 && na < n && nb >= 0 && nb < n && visited[na][nb]){
                        visited[a][b] = true;
                        q.push({a, b});
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && lit[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (lit[i][j]){
                count++;
            }
        }
    }
    cout << count;
}
