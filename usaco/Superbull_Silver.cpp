#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout); 
    long long int n, m;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int sum = 0;
    vector<bool> visited(n);
    priority_queue<pair<long long int, long long int>> pq;
    vector<int> maxedge(n, -1);
    maxedge[0] = 0;
    pq.push({0, 0});
    long long int count = 1;
    while(!pq.empty() && count <= n){
        auto current = pq.top();
        pq.pop();
        long long int l = current.first;
        long long int v = current.second;
        if(visited[v]){
            continue;
        }
        //cout << l << ' ' << v << endl;
        sum += l;
        visited[v] = true;
        for(int i = 0; i < n; i++){
            if(i != v && !visited[i]){
                if(maxedge[i] < (arr[v] ^ arr[i])){
                    pq.push({(arr[v] ^ arr[i]), i});
                    maxedge[i] = (arr[v] ^ arr[i]);
                }
            }
        }
    }
    //cout << (6 ^ 10) << endl;
    cout << sum;
}