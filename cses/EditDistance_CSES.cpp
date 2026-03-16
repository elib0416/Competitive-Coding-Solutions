#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    string a, b;
    cin >> a >> b;
    n = a.length();
    m = b.length();
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 1e9 + 7));
    for(int i = 0; i <= m; i++){
        arr[0][i] = i;
    }
    for(int i = 0; i <= n; i++){
        arr[i][0] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                arr[i][j] = min(arr[i][j], arr[i][j - 1] + 1);
                arr[i][j] = min(arr[i][j], arr[i - 1][j] + 1);
                arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
            }else{
                arr[i][j] = min(arr[i][j], arr[i][j - 1] + 1);
                arr[i][j] = min(arr[i][j], arr[i - 1][j] + 1);
                arr[i][j] = min(arr[i][j], arr[i - 1][j - 1] + 1);
            }
        }
    }
    /*for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << arr[n][m];
}