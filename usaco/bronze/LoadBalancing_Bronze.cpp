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
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cows(n);
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        cows[i].first = x[i];
        cows[i].second = y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int mini = 1e9 + 7;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a = 0, b = 0, c = 0, d = 0;
            for(auto p : cows){
                if(p.first <= x[i] && p.second <= y[j]){
                    a++;
                }else if(p.first <= x[i] && p.second > y[j]){
                    b++;
                }else if(p.first > x[i] && p.second <= y[j]){
                    c++;
                }else if(p.first > x[i] && p.second > y[j]){
                    d++;
                }
            }
            mini = min(mini, max(a, max(b, max(c, d))));
        }
    }
    cout << mini;
}