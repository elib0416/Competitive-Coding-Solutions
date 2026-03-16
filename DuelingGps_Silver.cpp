#include <bits/stdc++.h>
using namespace std;
struct edge{
    int a, b, c, d;
};
int main(){
    freopen("gpsduel.in", "r", stdin);
    freopen("gpsduel.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> paths, paths1, paths2;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        paths1[b].push_back({a, c});
        paths2[b].push_back({a, d});
        edges.push_back({a, b, c, d});
    }
    vector<int> arr(n, 1e9 + 7), arr1(n, 1e9 + 7), arr2(n, 1e9 + 7);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n - 1});
    arr[n - 1] = 0;
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int node = current.second;
        int cost = current.first;
        for(auto p : paths1[node]){
            int newnode = p.first;
            int addedcost = p.second;
            if(arr[newnode] > cost + addedcost){
                arr[newnode] = cost + addedcost;
                pq.push({cost + addedcost, newnode});
            }
        }
    }
    pq.push({0, n - 1});
    arr1[n - 1] = 0;
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int node = current.second;
        int cost = current.first;
        for(auto p : paths2[node]){
            int newnode = p.first;
            int addedcost = p.second;
            if(arr1[newnode] > cost + addedcost){
                arr1[newnode] = cost + addedcost;
                pq.push({cost + addedcost, newnode});
            }
        }
    }
    for(auto [x, y, c, d] : edges){
        int complaints = 0;
        if(arr[x] - arr[y] != c){
            complaints++;
        }
        if(arr1[x] - arr1[y] != d){
            complaints++;
        }
        paths[x].push_back({y, complaints});
    }
    
    pq.push({0, 0});
    arr2[0] = 0;
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int node = current.second;
        int cost = current.first;
        for(auto p : paths[node]){
            int newnode = p.first;
            int addedcost = p.second;
            if(arr2[newnode] > cost + addedcost){
                arr2[newnode] = cost + addedcost;
                pq.push({cost + addedcost, newnode});
            }
        }
    }
    cout << arr2[n - 1];
}