#include <bits/stdc++.h>
using namespace std;
const int maxn = 100002;
int n, m, a, b, maxSize = 0, maxnum;
vector<int> father(maxn), height(maxn), Size(maxn);
int find(int node){
    if (father[node] != node){
        father[node] = find(father[node]);
    }
    return father[node];
}
void unite(int A, int B){
    int rA = find(A);
    int rB = find(B);
    if(rA == rB){
        return;
    }
    maxnum--;
    if(height[rA] > height[rB]){
        father[rB] = rA;
        height[rA] = max(height[rA], height[rB] + 1);
        maxSize = max(maxSize, Size[rA] + Size[rB]);
        Size[rA] += Size[rB];
    }else{
        father[rA] = rB;
        height[rB] = max(height[rB], height[rA] + 1);
        maxSize = max(maxSize, Size[rA] + Size[rB]);
        Size[rB] += Size[rA];
    }
}
int main(){
    cin >> n >> m;
    maxnum = n;
    for(int i = 0; i < n; i++){
        height[i] = 0;
        father[i] = i;
        Size[i] = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        unite(a, b);
        cout << maxnum << ' ' << maxSize << endl;
    }
}