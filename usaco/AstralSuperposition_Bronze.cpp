#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
void solve(){
    int n, a, b;
    char c;
    map<char, int> number;
    number['W'] = 0;
    number['G'] = 1;
    number['B'] = 2;
    cin >> n >> a >> b;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            arr[i][j] = number[c];
        }
    }
    vector<vector<pair<int, int>>> stars(n, vector<pair<int, int>>(n, {0, 0})); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                stars[i][j] = {0, 0};
            }else if(arr[i][j] == 2){
                //cout << i << j << endl;
                stars[i][j] = {1, 1};
                int nx = i - b;
                int ny = j - a;
                //out << nx << ' ' << ny << endl;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] > 0){
                    if(arr[nx][ny] == 2){
                    }else{
                        //cout << "here";
                        stars[nx][ny] = {1, 0};
                    }
                }else{
                    cout << -1 << endl;
                    return;
                }
                //cout << stars[0][1].first;
                nx = i + b;
                ny = j + a;
                //cout << nx << ' ' << ny << endl;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 1){
                    stars[nx][ny] = {0, 1};  
                    //cout << 9 << endl;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && stars[i][j] == pair<int, int>{0, 0}){
                //untouched gray
                stars[i][j] = {1, 0};
                int nx = i + b;
                int ny = j + a;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 1 && stars[nx][ny] == pair<int, int>{0, 0}){
                    stars[nx][ny] = {0, 1};
                    //cout << nx << ' ' << ny << endl;
                }
            }
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(stars[i][j].first == 1){
                //cout << i << ' ' << j << endl;
                num++;
            }
        }
    }
    cout << num << endl;
}
int main(){
    //freopen("37.in", "r", stdin);
    //freopen("astral.out", "w", stdout);
    int t;
    cin >> t;
    //cout << t;
    while(t--){
        solve();
    }
}