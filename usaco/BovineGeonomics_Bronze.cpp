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
    char arr[4] = {'A', 'C', 'G', 'T'};
    int n, m, total = 0;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m)), b(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    for(int j = 0; j < m; j++){
        bool good = true;
        for(char c : arr){
            bool infirst = false;
            bool insecond = false;
            for(int i = 0; i < n; i++){
                if(a[i][j] == c){
                    infirst = true;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                if(b[i][j] == c){
                    insecond = true;
                    break;
                }
            }
            if(!infirst || !insecond){
                good = true;
            }else{
                good = false;
                break;
            }
        }
        if(good){
            total++;
        }
    }
    cout << total;
}