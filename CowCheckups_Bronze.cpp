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
    //freopen("37.in", "r", stdin);
    //freopen("astral.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n), ans(n + 1), doctor(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }
    for(int i = 0; i < n; i++){
        cin >> doctor[i];
        doctor[i]--;
    }
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            reverse(arr.begin() + l, arr.begin() + r + 1);
            int num = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] == doctor[i]){
                    num++;
                }
            }
            ans[num]++;
            reverse(arr.begin() + l, arr.begin() + r + 1);
        }
    }
    for(int i = 0; i <= n; i++){
        cout << ans[i] << endl;
    }
}