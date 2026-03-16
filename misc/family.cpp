#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int arr[maxn];
bool visited[maxn];
int numarr[maxn];
void dfs(int x){
    if(!visited[arr[x]]){
        visited[arr[x]] = true;
        //cout << x << " dfs " << arr[x] << ' ';
        dfs(arr[x]);
    }
}
void ldfs(int x){
    if(numarr[arr[x]] < 2){
        numarr[arr[x]]--;
        visited[arr[x]] = false;
        //cout << x << " dfs " << arr[x] << ' ';
        ldfs(arr[x]);
    }
}
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n, a, count = 0;
    cin >> n;
    //cout << n << ' ';
    for(int i = 0; i < n; i++){
        cin >> a;
        //cout << a << ' ';
        a--;
        arr[i] = a;
        numarr[a]++;
    }
    //cout << endl;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }else{
            ldfs(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(visited[i]){
            count++;
        }
    }
    cout << count;
}