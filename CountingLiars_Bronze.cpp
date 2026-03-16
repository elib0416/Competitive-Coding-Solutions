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
    //freopen("gymnastics.in", "r", stdin);
    //freopen("gymnastics.out", "w", stdout);
    int n, m, minnum = 1001;
    char c;
    cin >> n;
    vector<pair<char, int>> statements(n);
    set<int> arr;
    for(int i = 0; i < n; i++){
        cin >> statements[i].first >> statements[i].second;
        arr.insert(statements[i].second);
    }
    for(int x : arr){
        int num = 0;
        for(auto P : statements){
            if(P.first == 'G'){
                if(P.second > x){
                    num++;
                }
            }else{
                if(P.second < x){
                    num++;
                }
            }
        }
        minnum = min(minnum, num);
    }
    cout << minnum;
}