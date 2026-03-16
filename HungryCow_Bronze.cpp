#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> deliveries(n);
    long long total = 0;
    for(long long i = 0; i < n; i++){
        cin >> deliveries[i].first >> deliveries[i].second;
    }
    long long curhaybales = 0;
    for(long long i = 0; i < n - 1; i++){
        curhaybales += deliveries[i].second;
        long long curday = deliveries[i].first;
        long long nextday = deliveries[i + 1].first;
        long long numdays = nextday - curday;
        long long prevhaybales = curhaybales;
        curhaybales = max(static_cast<long long>(0), prevhaybales - numdays);
        total += prevhaybales - curhaybales;
    }
    //cout << total << endl;
    long long curday = deliveries[n - 1].first;
    curhaybales += deliveries[n - 1].second;
    total += min(m + 1 - curday, curhaybales);
    cout << total;
}