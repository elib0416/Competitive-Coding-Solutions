#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> target(n, vector<char>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> target[i][j];
            }
        }
        int m;
        cin >> m;
        vector<vector<vector<char>>> rotation(4, vector<vector<char>>(m, vector<char>(m)));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> rotation[0][i][j];
            }
        }
        for(int k = 1; k < 4; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    rotation[k][j][m - 1 - i] = rotation[k - 1][i][j];
                }
            }
        }
        vector<vector<bool>> covered(n, vector<bool>(n, false));
        for(int k = 0; k < 4; k++){
            for(int i = 0; i + m <= n; i++){
                for(int j = 0; j + m <= n; j++){
                    bool good = true;
                    for(int ii = 0; ii < m && good; ii++){
                        for(int jj = 0; jj < m; jj++){
                            if(rotation[k][ii][jj] == '*' &&
                               target[i + ii][j + jj] == '.'){
                                good = false;
                                break;
                            }
                        }
                    }
                    if(!good){
                        continue;
                    }
                    for(int ii = 0; ii < m; ii++){
                        for(int jj = 0; jj < m; jj++){
                            if(rotation[k][ii][jj] == '*'){
                                covered[i + ii][j + jj] = true;
                            }
                        }
                    }
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            for(int j = 0; j < n; j++){
                if(target[i][j] == '*' && !covered[i][j]){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n"; 
        }
    }
}
