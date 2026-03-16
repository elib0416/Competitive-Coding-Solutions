#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            char c;
            cin >> c;
            if(c == 'W'){
                arr[i][j] = 2;
                arr[j][i] = 0;
            }else if(c == 'D'){
                arr[i][j] = 1;
                arr[j][i] = 1;
            }else{
                arr[i][j] = 0;
                arr[j][i] = 2;
            }
        }
    }
    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        //cout << a << ' ' << b;
        int number = 0;
        for(int j = 1; j <= n; j++){
            if(arr[j][a] == 2 && arr[j][b] == 2){
                number++;
            }
        }
        cout << n * n - (n - number) * (n - number) << endl;
    }
}