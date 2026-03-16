#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> visited(n);
    vector<vector<int>> adjList(n), adjListback(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjListback[b].push_back(a);
    }
    int num = 1;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int x : adjList[cur]){
            if(!visited[x]){
                num++;
                q.push(x);
                visited[x] = true;
            }
        }
    }
    if(num != n){
        cout << "NO" << endl;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cout << 1 << ' ' << i + 1 << endl;
                return 0;
            }
        }
    }
    fill(visited.begin(), visited.end(), false);
    while(!q.empty()){
        q.pop();
    }
    q.push(0);
    visited[0] = true;
    num = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int x : adjListback[cur]){
            if(!visited[x]){
                num++;
                q.push(x);
                visited[x] = true;
            }
        }
    }
    if(num != n){
        cout << "NO" << endl;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cout << i + 1 << ' ' << 1 << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}