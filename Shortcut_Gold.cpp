#include <bits/stdc++.h>
using namespace std;
struct node{
   int v;
   long long w;
};
struct edge{
   int x;
   int w;
};
struct comp{
   bool operator()(node n1, node n2){
      return n1.w > n2.w;
   }
};
vector<int> ve(10005);
vector<long long> c(10005);
vector<long long> arr(10005);
vector<long long> numcows(10005);
int main(){
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
   int n, m;
   long t;
   cin >> n >> m >> t;
   for(int i = 1; i <= n; i++){
      cin >> c[i];
   }
   vector<vector<edge>> adj(n+1);
   for(int i = 0; i < m; i++){
      int a, b;
      int w;
      cin >> a >> b >> w;
      adj[a].push_back({b, w});
      adj[b].push_back({a, w});
   }
   for(int i = 0; i < 10005; i++){
       arr[i] = LONG_MAX;
   }
   arr[1] = 0;
   for(int i = 0; i < 10005; i++){
       ve[i] = -1;
   }
   priority_queue<node, vector<node>, comp> pq;
   pq.push({1, 0});
   unordered_set<int> visited;
   visited.insert(1);
   while(!pq.empty()){
      node cur = pq.top();
      pq.pop();
      int u = cur.v;
      visited.insert(u);
      for(edge e : adj[u]){
        int v = e.x;
        if(visited.find(v) != visited.end()){
            continue;
        }
        long long ndis = arr[u] + e.w;
        if(ndis < arr[v]){
            arr[v] = ndis;
            ve[v] = u;
            pq.push({v, ndis});
        }else if(ndis == arr[v]){                     
            if(u < ve[v]){
               arr[v] = ndis;
               ve[v] = u;
               pq.push({v, ndis});
            }
         }
      }
   }
   for(int j = 1; j <= n; j++){
      int i = j;
      while(i != -1){
         numcows[i] += c[j];
         i = ve[i];
      }
   }
   long long answer = 0;
   for(int i = 1; i <= n; i++){
      answer = max(answer, numcows[i] * (arr[i] - t));
      //cout << arr[i] << ' ';
   }
   cout << answer << endl;
}