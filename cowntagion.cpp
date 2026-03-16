#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
vector<int> adj[maxn];
int dfs(int x, int p){
    int targetcows = adj[x].size();
    if(p == -1){
        targetcows++;
    }
    int curcows = 1, numdays = 0;
    while(curcows < targetcows){
        curcows *= 2;
        numdays++;
    }
    for(int y : adj[x]){
        if(y != p){
            numdays += 1 + dfs(y, x);
        }
    }
    return numdays;
}
int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(0, -1);
}
