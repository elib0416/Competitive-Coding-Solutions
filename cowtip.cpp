#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num = 0;
    char c;
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            arr[i][j] = c - '0';
            //cout << arr[i][j] << ' ';
        }
        //cout << endl;
    }
    vector<vector<int>> target(n, vector<int>(n));
    int curx = n - 1, cury = n - 1;
    while(curx >= 0 && cury >= 0){
        if(arr[curx][cury]){
            for(int i = 0; i <= curx; i++){
                for(int j = 0; j <= cury; j++){
                    arr[i][j] = 1 - arr[i][j];
                }
            }
            num++;
        }
        if(curx != cury && arr[cury][curx]){
            for(int i = 0; i <= cury; i++){
                for(int j = 0; j <= curx; j++){
                    arr[i][j] = 1 - arr[i][j];
                }
            }
            num++;
        }
        if(curx > 0){
            curx--;
        }else{
            cury--;
            curx = cury;
        }
    }
    cout << num;
}