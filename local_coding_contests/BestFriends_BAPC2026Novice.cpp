#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n,q;
    cin >> n >> q;
    set <ll> indegree;
    // amounts that doesnt 
    vector <ll> cur_point(n+1,0);
    vector <ll> amount(n+2,0);
    vector <ll> current_best(n+1);
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        current_best[i] = a;
    }
    for (auto &p : current_best){
        cur_point[p] += 1;
    }
    for (int i = 1; i<= n; i++){
        amount[cur_point[i]] += 1;
    }
    for (int i = 0; i <= n+1; i++){
        if (amount[i] == 0){
            indegree.insert(i);
        }
    }
    for (int i = 0; i < q; i++){
        ll t;
        cin >> t;
        if (t == 1){
            ll a,b;
            cin >> a >> b;
            ll cur = current_best[a];
            amount[cur_point[cur]] -= 1;
            if (amount[cur_point[cur]] == 0){
                indegree.insert(cur_point[cur]);
            }
            cur_point[cur] -= 1;
            amount[cur_point[cur]] += 1;
            if (amount[cur_point[cur]] == 1){
                indegree.erase(cur_point[cur]);
            }
            
            
            current_best[a] = b;
            amount[cur_point[b]] -= 1;
            if (amount[cur_point[b]] == 0){
                indegree.insert(cur_point[b]);
            }
            cur_point[b] += 1;
            amount[cur_point[b]] += 1;
            if (amount[cur_point[b]] == 1){
                indegree.erase(cur_point[b]);
            }
        }
        else{
            auto it = indegree.begin();
            cout << *it << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}