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
    int n, u, a, b;
    cin >> n >> u;
    int m = n / 2;
    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<int>> painted(m, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(arr[m + i][m + j] == '#'){
                painted[i][j]++;
            }
            if(arr[m - 1 - i][m + j] == '#'){
                painted[i][j]++;
            }
            if(arr[m + i][m - 1 - j] == '#'){
                painted[i][j]++;
            }
            if(arr[m - 1 - i][m - 1 - j] == '#'){
                painted[i][j]++;
            }
            sum += min(painted[i][j], 4 - painted[i][j]);
        }
    }
    cout << sum << endl;
    for(int i = 0; i < u; i++){
        cin >> a >> b;
        a--;
        b--;
        int x = m - a - 1, y = m - b - 1;
        if(a >= m){
            x = a - m;
        }
        if(b >= m){
            y = b - m;
        }
        //cout << a << ' ' << b << ' ' << x << ' ' << y << endl;
        sum -= min(painted[x][y], 4 - painted[x][y]);
        if(arr[a][b] == '#'){
            arr[a][b] = '.';
        }else{
            arr[a][b] = '#';
        }
        painted[x][y] = 0;
        if(arr[m + x][m + y] == '#'){
            painted[x][y]++;
        }
        if(arr[m - 1 - x][m + y] == '#'){
            painted[x][y]++;
        }
        if(arr[m + x][m - 1 - y] == '#'){
            painted[x][y]++;
        }
        if(arr[m - 1 - x][m - 1 - y] == '#'){
            painted[x][y]++;
        }
        sum += min(painted[x][y], 4 - painted[x][y]);
        cout << sum << endl;
    }
}