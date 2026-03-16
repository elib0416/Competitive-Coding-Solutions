#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    const long long int infi = 1e9 + 7;
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> choices(n);
    for(int i = 0; i < n; i++){
        cin >> choices[i].first >> choices[i].second;
        choices[i].first--;
        choices[i].second--;
    }
    string s = "";
    char c;
    for(int i = 0; i < m; i++){
        cin >> c;
        s += c;
    }
    vector<int> went(n, 0);
    int node = 0;
    int t = 0;
    while(went[node] == 0){
        went[node] = t;
        for(char c : s){
            if(c == 'L'){
                node = choices[node].first;
            }else{
                node = choices[node].second;
            }
        }
        //cout << t << ' ' << node << endl;
        t++;
    }
    if(t < k){
        int eachtime = t - went[node];
        int currentmod = went[node] % eachtime;
        int targetmod = k % eachtime;
        while(currentmod != targetmod){
            currentmod++;
            currentmod %= eachtime;
            for(char c : s){
                if(c == 'L'){
                    node = choices[node].first;
                }else{
                    node = choices[node].second;
                }
            }
        }
        cout << node + 1;
    }else if(t == k){
        cout << node + 1;
    }else{
        for(int i = 0; i < n; i++){
            if(went[i] == k){
                cout << i + 1;
            }
        }
    }
}