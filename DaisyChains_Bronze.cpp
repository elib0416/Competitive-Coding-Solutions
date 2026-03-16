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
    //freopen("37.in", "r", stdin);
    //freopen("astral.out", "w", stdout);
    int n, m, sum = 0, num = 0;
    cin >> n;
    vector<int> pref(n + 1), arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
        sum += arr[i];
    }
    /*for(int i = 0; i <= n; i++){
        cout << pref[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }*/
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            //cout << i << ' ' << j << endl;
            int total = pref[j + 1] - pref[i];
            int numterms = j - i + 1;
            int q = total / (numterms);
            if(total % numterms == 0){
                for(int k = i; k <= j; k++){
                    if(arr[k] == q){
                        //cout << "found" << endl;
                        num++;
                        //cout << num << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << num;
}