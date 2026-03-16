#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long int infi = 1e9 + 7;
    long long int n, m, k;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> distances(n, infi);
    vector<vector<int>> breeds(m);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
        breeds[arr[i]].push_back(i);
    }
    vector<vector<int>> willing(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '1'){
                willing[i].push_back(j);
            }
        }
    }
    distances[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int t = current.first;
        int curnode = current.second;
        int curbreed = arr[curnode];
        for(int nextbreed : willing[curbreed]){
            for(int nextnode : breeds[nextbreed]){
                if(distances[nextnode] > t + abs(nextnode - curnode)){
                    distances[nextnode] = t + abs(nextnode - curnode);
                    pq.push({t + abs(nextnode - curnode), nextnode});
                }
            }
        }
    }
    if(distances[n - 1] == infi){
        cout << -1;
        return 0;
    }
    cout << distances[n - 1];
}