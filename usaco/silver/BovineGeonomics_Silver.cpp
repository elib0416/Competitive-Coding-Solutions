#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <set>
using namespace std;
int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    char genes[4] = {'A', 'C', 'G', 'T'};
    int n, m, total = 0;
    cin >> n >> m;
    vector<vector<char>> spotty(n, vector<char>(m)), plain(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> spotty[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> plain[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                //cout << i << ' ' << j << ' ' << k << endl;
                bool ok = true;
                map<string, bool> isspotty;
                for(int in = 0; in < n; in++){
                    string str = "";
                    str += spotty[in][i];
                    str += spotty[in][j];
                    str += spotty[in][k];
                    isspotty[str] = true;
                }
                for(int in = 0; in < n; in++){
                    string str = "";
                    str += plain[in][i];
                    str += plain[in][j];
                    str += plain[in][k];
                    if(isspotty[str]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    //cout << i << ' ' << j << ' ' << k << endl;
                    total += ok;
                }
            }
        }
    }
    cout << total;
}