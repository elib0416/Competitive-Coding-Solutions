#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    map<int, vector<int>> paths;
    vector<int> visited (n, 0);
    vector<int> visited1;
    vector<int> indexes (n + 1, 0);
    visited1 = visited;
    int x, y;
    for(int i = 0; i < m ; i++){
        cin >> x >> y;
        paths[--x].push_back(--y);
        paths[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        cin >> indexes[i];
        //cout << indexes[i] << ' ' << i << endl;
    }
    for(int i = 0; i < n; i++){
        //cout << i;
        visited = visited1;
        if(i != 0){
            int index = indexes[i];
            visited[--index] = 1;
        }
        //int index = indexes[i];
        //visited[--index] = 1;
        visited1 = visited;
        int j = 0;
        while(visited[j]){
            j++;
            continue;
        }
        int counter = 1;
        queue<int> q;
        q.push(j);
        visited[j] = 1;
        bool connected = false;
        while(!q.empty()){
            if(counter == n - i){
                connected = true;
                //break;
            }
            int current = q.front();
            q.pop();
            if(paths.find(current) != paths.end()){
                for(int n1 : paths[current]){
                    if(!visited[n1]){
                        q.push(n1);
                        counter++;
                        //cout << n1 << ' ' << counter << ' ' << i << endl;
                        visited[n1] = 1;
                    }
                }
            }
        }
        if(connected){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    //cout << "finished";
    return 0;
}