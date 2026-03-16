#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
struct place{
    int x, y, maxh;
};
const int dirx[4] = {1, -1, 0, 0};
const int diry[4] = {0, 0, 1, -1};
int main(){
    int n, m, a, x, y, c, d;
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> a;
    //cout << a;
    vector<vector<vector<int>>> p(n, vector<vector<int>>(m));
    for(int i = 0; i < a; i++){
        cin >> x >> y;
        //cout << x << ' ' << y << endl;
        x--;
        y--;
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<place> q;
        q.push({x, y, arr[x][y]});
        visited[x][y] = true;
        p[x][y].push_back(arr[x][y]);
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = current.x + dirx[i];
                int ny = current.y + diry[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && abs(arr[nx][ny] - arr[current.x][current.y]) <= 1){
                    q.push({nx, ny, max(current.maxh, arr[nx][ny])});
                    visited[nx][ny] = true;
                    p[nx][ny].push_back(max(current.maxh, arr[nx][ny]));
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sort(p[i][j].begin(), p[i][j].end());
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> c >> d;
        bool done = false;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(p[x][y].size() < d){
                    continue;
                }
                int dis;
                if(c >= p[x][y].back()){
                    dis = p[x][y].size();
                }else{
                    dis = upper_bound(p[x][y].begin(), p[x][y].end(), c) - p[x][y].begin();
                }
                if(dis >= d){
                    cout << x + 1 << ' ' << y + 1 << '\n';
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
        }
        if(done){
            continue;
        }
        cout << -1 << ' ' << -1 << '\n';
    }
}