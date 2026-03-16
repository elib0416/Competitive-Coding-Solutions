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
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout); 
    int n, m, k;
    cin >> n >> m >> k;
    char c;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<char>> multiply((n * k), vector<char>((m * k)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < k * n; i++){
        for(int j = 0; j < k * m; j++){
            multiply[i][j] = arr[i / k][j / k];
        }
    }
    for(int i = 0; i < k * n; i++){
        for(int j = 0; j < k * m; j++){
            cout << multiply[i][j];
        }
        cout << endl;
    }
}