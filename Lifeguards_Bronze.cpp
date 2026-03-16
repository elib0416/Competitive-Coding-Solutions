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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n, a, b, total = 0, minsubtract = 1e9 + 7;
    cin >> n;
    vector<int> diff(1001);
    vector<int> times(1001);
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        diff[a]++;
        diff[b]--;
        arr[i].first = a;
        arr[i].second = b;
    }
    times[0] = diff[0];
    for(int i = 1; i <= 1000; i++){
        times[i] = times[i - 1] + diff[i];
        if(times[i] > 0){
            total++;
        }
    }
    for(int i = 0; i < n; i++){
        //cout << arr[i].first << ' ' << arr[i].second << endl;
        int count = 0;
        for(int j = arr[i].first; j < arr[i].second; j++){
            if(times[j] == 1){
                count++;
            }
        }
        minsubtract = min(minsubtract, count);
    }
    //cout << total << ' ' << minsubtract << endl;
    cout << total - minsubtract;
}