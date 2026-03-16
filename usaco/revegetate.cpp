#include <bits/stdc++.h>
using namespace std;
struct nod{
    char c;
    int index;
};
int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<nod>> adj(n);
    vector<int> visited(n);
    int num = 0;
    char c;
    for(int i = 0; i < m; i++){
        cin >> c >> a >> b;
        a--;
        b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for(int in = 0; in < n; in++){
        if(visited[in] != 0){
            continue;
        }
        num++;
        queue<int> q;
        q.push(in);
        visited[in] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(nod no : adj[cur]){
                if(no.c == 'S'){
                    if((visited[no.index] == 1 && visited[cur] == 2) || (visited[no.index] == 2 && visited[cur] == 1)){
                        cout << 0;
                        return 0;
                    }else{
                        if(visited[no.index] == 0){
                            q.push(no.index);
                        }
                        visited[no.index] = visited[cur];
                    }
                }else{
                    if((visited[no.index] == 2 && visited[cur] == 2) || (visited[no.index] == 1 && visited[cur] == 1)){
                        cout << 0;
                        return 0;
                    }else{
                        if(visited[no.index] == 0){
                            q.push(no.index);
                        }
                        visited[no.index] = 3 - visited[cur];
                    }
                }
            }
        }
    }
    cout << 1;
    while(num--){
        cout << 0;
    }
}