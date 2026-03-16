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
    long long int total = 0;
    cin >> n;
    int a;
    set<int> distincts;
    vector<int> arr(n);
    vector<int> pref(n);
    //note to self: 0 - index
    map<int, vector<int>> spots;
    //map<int, int> firsttime;
    //set<int> secondtimes;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        spots[arr[i]].push_back(i);
        distincts.insert(arr[i]);
        pref[i] = distincts.size();
        
    }
    for(int x : distincts){
        int si = spots[x].size();
        if(si < 2){
            continue;
        }else{
            int index = spots[x][si - 2];
            total += pref[index] - 1;
        }
    }
    cout << total;
}