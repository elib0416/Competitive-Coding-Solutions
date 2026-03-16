#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int rotated_n = 2 * n - 1;
    vector<vector<int>> arr(rotated_n, vector<int>(rotated_n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i + j][n - i + j - 1];
        }
    }
    /*for(int i = 0; i < rotated_n; i++){
        for(int j = 0; j < rotated_n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }*/
    vector<vector<int>> prf(rotated_n + 1, vector<int>(rotated_n + 1, 0));
    int most_grass = -1;
    for(int i = 0; i < rotated_n; i++){
        for(int j = 0; j < rotated_n; j++){
			int add = max(arr[i][j], 0);
            prf[i + 1][j + 1] = (add + prf[i + 1][j] + prf[i][j + 1] - prf[i][j]);
            //cout << prf[i][j] << ' ';
        }
        //cout << endl;
    }
    for(int i = k; i < rotated_n - k; i++){
        for(int j = k; j < rotated_n - k; j++){
            if(arr[i][j] == -1){
                continue;
            }else{
                most_grass = max(most_grass, prf[i + k + 1][j + k + 1] - prf[i - k][j + k + 1] - prf[i + k + 1][j - k] + prf[i - k][j - k]);
                //cout << arr[i][j] << "turns " << most_grass << endl;
            }
        }
    }
    if(k >= n){
        most_grass = prf[rotated_n][rotated_n];
    }
    cout << most_grass;
}