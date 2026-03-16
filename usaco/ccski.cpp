#include <bits/stdc++.h>
using namespace std;
const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};
bool bfs(int n, int m, int d, vector<vector<int>>& map, vector<pair<int, int>>& wayp){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, int>> q;
    q.push(wayp[0]);
    visited[wayp[0].first][wayp[0].second] = true;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && abs(map[nx][ny] - map[x][y]) <= d){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    for(auto p : wayp){
        if(!visited[p.first][p.second]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n, m, a;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    //vector<vector<bool>> iswaypoi
    vector<pair<int, int>> wayp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            if(a){
                wayp.push_back({i, j});
            }
        }
    }
    if(wayp.size() == 0){
        cout << 0;
        return 0;
    }
    int lo = 0;
    int hi = 1e9 + 1;
    int ans = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        //cout << mid << ' ';
        if(bfs(n, m, mid, map, wayp)){
            ans = mid;
            hi = mid - 1;
            //cout << "yes high is " << hi << endl;
        }else{
            lo = mid + 1;
            //cout << "no low is " << lo << endl;
        }
    }
    cout << ans;
}
