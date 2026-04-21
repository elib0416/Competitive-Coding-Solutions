#include <bits/stdc++.h>
using namespace std;
struct node{
    long long int x, y, n;
};
long long int dirx[4] = {1, -1, 0, 0};
long long int diry[4] = {0, 0, 1, -1};
bool valid(long long int x, long long int y, long long int n){
    return (x >= 0 && x < n && y >= 0 && y < n);
}
struct compare{
    bool operator()(node& a, node& b){
        return a.n < b.n;
    }
};
int main(){
    long long int n, d;
    cin >> n >> d;
    vector<vector<char>> arr(n, vector<char>(n));
    vector<pair<long long int, long long int>> sources;
    vector<pair<long long int, long long int>> walls;
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                sources.push_back({i, j});
            }else if(arr[i][j] == '#'){
                walls.push_back({i, j});
            }
        }
    }
    vector<vector<long long int>> walldist(n, vector<long long int>(n, 1e9 + 7));
    queue<node> q;
    for(auto [x, y] : walls){
        walldist[x][y] = 0;
        q.push({x, y, 0});
    }
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        long long int x = current.x;
        long long int y = current.y;
        for(long long int i = 0; i < 4; i++){
            long long int nx = x + dirx[i];
            long long int ny = y + diry[i];
            if(valid(nx, ny, n) && walldist[nx][ny] > current.n + 1){
                //cout << nx << ' ' << ny << ' ' << current.n << endl;
                q.push({nx, ny, current.n + 1});
                walldist[nx][ny] = current.n + 1;
            }
        }
    }
    vector<vector<long long int>> sourcedist(n, vector<long long int>(n, 1e9 + 7));
    vector<vector<long long int>> robottime(n, vector<long long int>(n, -1));
    vector<vector<long long int>> visited(n, vector<long long int>(n, -1));
    priority_queue<node, vector<node>, compare> pq;
    for(auto [x, y] : sources){
        sourcedist[x][y] = 0;
        robottime[x][y] = max(sourcedist[x][y] / d, walldist[x][y] - 1);
        q.push({x, y, 0});
        pq.push({x, y, robottime[x][y]});
        visited[x][y] = robottime[x][y];
    }
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        long long int x = current.x;
        long long int y = current.y;
        for(long long int i = 0; i < 4; i++){
            long long int nx = x + dirx[i];
            long long int ny = y + diry[i];
            if(valid(nx, ny, n) && sourcedist[nx][ny] > current.n + 1 && walldist[nx][ny] * d >= current.n + 1 && arr[nx][ny] != '#'){
                if(walldist[nx][ny] * d > current.n + 1){
                    q.push({nx, ny, current.n + 1});
                }
                sourcedist[nx][ny] = current.n + 1;
                robottime[nx][ny] = min(sourcedist[nx][ny] / d, walldist[nx][ny] - 1);
                pq.push({nx, ny, robottime[nx][ny]});
                visited[nx][ny] = robottime[nx][ny];
            }
        }
    }
    /*a(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }*/
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        long long int x = current.x;
        long long int y = current.y;
        if(current.n <= 0){
            continue;
        }
        for(long long int i = 0; i < 4; i++){
            long long int nx = x + dirx[i];
            long long int ny = y + diry[i];
            if(valid(nx, ny, n) && arr[nx][ny] != '#' && current.n - 1 > visited[nx][ny]){
                pq.push({nx, ny, current.n - 1});
                visited[nx][ny] = max(visited[nx][ny], current.n - 1);
            }
        }
    }
    /*for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cout << walldist[i][j] << ' ';
        }
        cout << endl;
    }
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cout << sourcedist[i][j] << ' ';
        }
        cout << endl;
    }
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cout << robottime[i][j] << ' ';
        }
        cout << endl;
    }
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }*/
    long long int ans = 0;
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            if(visited[i][j] >= 0){
                ans++;
            }
        }
    }
    cout << ans;
}