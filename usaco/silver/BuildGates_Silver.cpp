#include <bits/stdc++.h>
using namespace std;
const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};
int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> arr(4008, vector<int>(4008));
    arr[2002][2002] = -1;
    int curx = 2002;
    int cury = 2002;
    int minx = 1e9 + 7, miny = 1e9 + 7, maxx = -1e9 - 7, maxy = -1e9 - 7;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'N'){
            arr[++curx][cury] = -1;
            arr[++curx][cury] = -1;
        }else if(c == 'S'){
            arr[--curx][cury] = -1;
            arr[--curx][cury] = -1;
        }else if(c == 'E'){
            arr[curx][++cury] = -1;
            arr[curx][++cury] = -1;
        }else{
            arr[curx][--cury] = -1;
            arr[curx][--cury] = -1;
        }
        minx = min(minx, curx);
        miny = min(miny, cury);
        maxx = max(maxx, curx);
        maxy = max(maxy, cury);
    }
    minx--;
    miny--;
    maxx++;
    maxy++;
    int ans = -1;
    for(int i = minx; i <= maxx; i++){
        for(int j = miny; j <= maxy; j++){
            if(arr[i][j] == -1){
                continue;
            }
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            arr[i][j] = -1;
            while(!q.empty()){
                auto cur = q.front();
                int x = cur.first;
                int y = cur.second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + dirx[k];
                    int ny = y + diry[k];
                    if(arr[nx][ny] != -1 && nx >= minx && ny >= miny && nx <= maxx && ny <= maxy){
                        arr[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << ans;
}
