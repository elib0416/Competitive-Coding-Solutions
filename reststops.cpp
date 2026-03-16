#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long int, long long int>& A, pair<long long int, long long int>& B){
    return A.second > B.second;
}
int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    long long int l, n, f, b, diff;
    long long int tastiness = 0;
    cin >> l >> n >> f >> b;
    diff = f - b;
    vector<pair<long long int, long long int>> arr(n);
    for(long long int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);
    long long int pos = 0, distance;
    for(pair<long long int, long long int> p : arr){
        if (p.first < pos){
            continue;
        }else{
            distance = p.first - pos;
            //cout << p.first << ' ' << p.second << ' ' << distance * diff * p.second << endl;
            tastiness += distance * diff * p.second;
            //cout << tastiness;
            pos = p.first;
        }
    }
    cout << tastiness;
}