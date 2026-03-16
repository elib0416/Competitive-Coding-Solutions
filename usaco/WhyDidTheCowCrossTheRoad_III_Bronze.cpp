#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> start(n);
    for(int i = 0; i < n; i++){
        cin >> start[i].first >> start[i].second;
    }
    sort(start.begin(), start.end());
    int t = 0;
    for(int i = 0; i < n; i++){
        t = max(t, start[i].first);
        t += start[i].second;
    }
    cout << t;
}