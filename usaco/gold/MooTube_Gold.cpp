#include <bits/stdc++.h>
using namespace std;
long long maxn = 100001;
vector<int> number(maxn, 0);
struct dsu{
    vector<long long int> parent, rank;
    void intitialize(long long int n){
        parent.resize(n);
        rank.resize(n);
        for(long long int i = 0; i < n; i++){
            rank[i] = 0;
            parent[i] = i;
            number[i]++;
        }
    }
    long long int findparent(long long int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = findparent(parent[x]);
        return parent[x];
    }
    void connect(long long int x, long long int y){
        long long int a = findparent(x);
        long long int b = findparent(y);
        if(rank[a] < rank[b]){
            number[b] += number[a];
            number[a] = 0;
            parent[a] = b;
        }else if(rank[b] < rank[a]){
            number[a] += number[b];
            number[b] = 0;
            parent[b] = a;
        }else{
            number[a] += number[b];
            number[b] = 0;
            parent[b] = a;
            rank[a]++;
        }
    }
};
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(n - 1);
    vector<pair<int, int>> cores(n - 1);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {a, b};
        cores[i] = {c, i};
    }
    sort(cores.begin(), cores.end(), greater<pair<int, int>>());
    vector<pair<int, int>> queries(m);
    vector<pair<int, int>> corresponding(m);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        b--;
        queries[i] = {a, b};
        corresponding[i] = {a, i};
    }
    sort(corresponding.begin(), corresponding.end(), greater<pair<int, int>>());
    /*cout << "EDGES: ";
    for(auto [x, y] : edges){
        cout << x << ' ' << y << " | ";
    }
    cout << endl;
    cout << "CORES: ";
    for(auto [x, y] : cores){
        cout << x << ' ' << y << " | ";
    }
    cout << endl;
    cout << "QUERIES: ";
    for(auto [x, y] : queries){
        cout << x << ' ' << y << " | ";
    }
    cout << endl;
    cout << "CORRESPONDING: ";
    for(auto [x, y] : corresponding){
        cout << x << ' ' << y << " | ";
    }
    cout << endl;*/
    dsu DSU;
    DSU.intitialize(n);
    int j = 0;
    vector<int> answer(m);
    for(int i = 0; i < m; i++){
        int k = corresponding[i].first;
        int index = corresponding[i].second;
        while(j < n - 1 && cores[j].first >= k){
            DSU.connect(edges[cores[j].second].first, edges[cores[j].second].second);
            j++;
        }
        answer[index] = number[DSU.findparent(queries[index].second)] - 1;
    }
    for(int i = 0; i < m; i++){
        cout << answer[i] << endl;
    }
}