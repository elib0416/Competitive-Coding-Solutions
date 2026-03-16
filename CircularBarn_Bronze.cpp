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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout); 
    int n, a, mini = 1e9;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int num = 0;
        for(int j = 1; j <= n - 1; j++){
            num += j * arr[(i + j) % n];
        }
        mini = min(mini, num);
    }
    cout << mini;
}