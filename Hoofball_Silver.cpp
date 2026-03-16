#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n), ins(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if(n <= 2){
        cout << 1;
        return 0;
    }
    vector<int> to(n);
    to[0] = 1;
    to[n - 1] = n - 2;
    ins[1]++;
    ins[n - 2]++;
    for(int i = 1; i < n - 1; i++){
        int a = arr[i] - arr[i - 1];
        int b = arr[i + 1] - arr[i];
        if(a <= b){
            ins[i - 1]++;
            to[i] = i - 1;
        }else{
            to[i] = i + 1;
            ins[i + 1]++;
        }
    }
    int count = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        //cout << ins[i] << ' ';
        if(ins[i] == 0){
            count++;
            visited[i] = true;
            int current = i;
            while(!visited[to[current]]){
                visited[to[current]] = true;
                current = to[current];
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            int current = i;
            while(!visited[to[current]]){
                visited[to[current]] = true;
                current = to[current];
            }
        }
    }
    cout << count;
}