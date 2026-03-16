#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int diffarr[1002][1002];
    int pfx[1002][1002];
    memset(diffarr, 0, sizeof(diffarr));
    memset(pfx, 0, sizeof(pfx));
    int n, k;
    cin >> n >> k;
    int x, y, x1, y1;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> x1 >> y1;
        //cout << x << ' ' << y << ' ' << x1 << ' ' << y1 << endl;
        diffarr[x][y]++;
        diffarr[x][y1]--;
        diffarr[x1][y]--;
        diffarr[x1][y1]++;
    }
    /*for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            cout << diffarr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-----\n";*/
    long long int cnt = 0;
    for(int i = 1; i <= 1000; i++){
        pfx[0][i] = pfx[0][i - 1] + diffarr[0][i];
        pfx[i][0] = pfx[i - 1][0] + diffarr[i][0];
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            pfx[i][j] = pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1] + diffarr[i][j];
            if(pfx[i][j] == k){
                cnt++;
            }
        }
    }
    /*for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            cout << pfx[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << cnt;
}