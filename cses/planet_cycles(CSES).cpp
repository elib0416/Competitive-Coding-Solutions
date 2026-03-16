#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
int dis[maxn] = {0};
int ans[maxn] = {0};
int tp[maxn];
void place(int n, int x){
    if(ans[n] == 0){
        ans[n] = x;
        place(tp[n], x);
    }
}
void place2(int n, int x, int termination_point){
    if(ans[n] == 0){
        ans[n] = x;
    }
    if(n != termination_point){
        place2(tp[n], x - 1, termination_point);
    }
}
void dfs(int n, int depth, int root){
    if(ans[n] != 0){
        //cout << root << " exited because came into or was part of an existing loop" << endl;
        ans[root] = depth + ans[n];
        return;
    }else if(dis[n] != -1){
        //cout << root << " exited because found a new loop" << endl;
        place(n, depth - dis[n]);
        place2(root, depth, n);
        return;
    }else{
        dis[n] = depth;
        //cout << n << " to " << tp[n] << endl;
        dfs(tp[n], depth + 1, root);
        dis[n] = -1;
    }
}
int main(){
    int n;
    cin >> n;
    memset(dis, -1, sizeof(dis));
    for(int i = 0; i < n; i++){
        cin >> tp[i];
        tp[i]--;
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == 0){
            dfs(i, 0, i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}