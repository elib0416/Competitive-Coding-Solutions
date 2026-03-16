#include <bits/stdc++.h>
using namespace std;
int ceildiv (int n, int d){
    if(n % d == 0){
        return n / d;
    }
    return n / d + 1; 
}
int main(){
    int n;
    cin >> n;
    vector<int> cows(n), groups, edge;
    int edges = 0;
    int groupsize = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        cows[i] = c - '0';
        if(cows[i]){
            groupsize++;
        }else{
            if(groupsize){
                if(groupsize == i){
                    edges++;
                    edge.push_back(groupsize);
                    groupsize = 0;
                    continue;
                }
                groups.push_back(groupsize);
                groupsize = 0;
            }
        }
    }
    if(cows[n - 1]){
        edges++;
        edge.push_back(groupsize);
    }
    int minnum = 1e9;
    for(int x : groups){
        minnum = min(minnum, x);
    }
    for(int x : edge){
        minnum = min(minnum, 2 * x - 1);
    }
    if(groupsize == n){
        cout << 1;
        return 0;
    }
    int days = (minnum - 1) / 2;
    int total = 0;
    for(int x : edge){
        total += ceildiv(x, 2 * days + 1);
    }
    //cout << days << endl;
    for(int x : groups){
        total += ceildiv(x, 2 * days + 1);
    }
    cout << total;
}