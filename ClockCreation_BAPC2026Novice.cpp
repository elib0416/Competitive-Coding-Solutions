#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
vector <ll> primes;
void solve(){
    ll n;
    cin >> n;
    vector <ll> l1;
    for (auto &p : primes){
        ll cur = 1;
        while (n % p == 0){
            n /= p;
            cur *= p;
        } 
        if (cur != 1){
            l1.push_back(cur);
        }
    }
    cout << l1.size()<< "\n";
    for (auto &p : l1){
        cout << p << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector <ll> check(1e5+1, 0);
    for (int i = 2; i < 1e5+1; i++){
        if (check[i]){
            continue;
        }
        primes.push_back(i);
        for (int j = i; j <= 100000; j+=i){
            check[j] = 1;
        }
    }
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}