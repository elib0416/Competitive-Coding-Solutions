#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, a, b, c;
    long long int num = 0;
    cin >> n >> m;
    vector<vector<int>> xy(n, vector<int>(n)), yz(n, vector<int>(n)), xz(n, vector<int>(n));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        xy[a][b]++;
        if(xy[a][b] == n){
            num++;
        }
        yz[b][c]++;
        if(yz[b][c] == n){
            num++;
        }
        xz[a][c]++;
        if(xz[a][c] == n){
            num++;
        }
        cout << num << endl;
    }
}