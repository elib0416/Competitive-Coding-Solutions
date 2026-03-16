#include <bits/stdc++.h>
using namespace std;
struct dsu{
    vector<long long int> parent, rank;
    void intitialize(long long int n){
        parent.resize(n);
        rank.resize(n);
        for(long long int i = 0; i < n; i++){
            rank[i] = 0;
            parent[i] = i;
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
            parent[a] = b;
            
        }else if(rank[b] < rank[a]){
            parent[b] = a;
        }else{
            parent[a] = b;
            rank[a]++;
        }
    }
};