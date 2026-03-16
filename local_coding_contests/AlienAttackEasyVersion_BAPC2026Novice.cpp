#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct item{
    ll t,a,b;
};

void dfs(ll a, ll b, ll c, ll &answ, ll &tar, vector <vector <ll>> &adj, vector <ll> &val){
    b += val[a];
    if (a == tar){
        answ = b;
        return;
    }
    for (auto &p : adj[a]){
        if (p != c){
            dfs(p, b, a, answ, tar, adj, val);
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    vector <vector <ll>> adj(n+1);
    vector <ll> vals(n+1);
    for (int i = 0; i < n-1; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <item> q1;
    vector <item> q2;
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++){
        ll idk;
        cin >> idk;
        if (idk == 1){
            ll t,a,b;
            cin >> t >> a >> b;
            q1.push_back({t,a,b});
        }
        else{
            ll t,a,b;
            cin >> t >> a >> b;
            q2.push_back({t,a,b});
        }
    }
    for (auto &p : q2){
        vector <ll> new_vals = vals;
        for (auto &c : q1){
            if (c.t <= p.t){
                new_vals[c.a] = c.b - (p.t - c.t);
            }
        }
        ll answ = 0;
        dfs(p.a, 0LL, 0LL, answ, p.b, adj, new_vals);
        cout << answ << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}