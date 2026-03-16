#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n, a, b;
    cin >> n;
    map<int, vector<int>> paths;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        paths[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        bool goodsofar = true;
        for(int j = 1; j <= n; j++){
            if(j == i){
                continue;
            }
            vector<bool> visited(n + 1);
            queue<int> q;
            q.push(j);
            visited[j] = true;
            while(!q.empty()){
                int current = q.front();
                q.pop();
                for(int x : paths[current]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
            if(visited[i]){
                continue;
            }else{
                goodsofar = false;
                break;
            }
        }
        if(goodsofar){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}