#include <bits/stdc++.h>
using namespace std;
bool comparepair(pair<long long int, long long int>& A, pair<long long int, long long int>& B){
    return A.first < B.first;
}
bool isPossible(long long int n, long long int m, vector<pair<long long int, long long int>>& field, long long int d, long long int lb, long long int hb) {
    long long int i = 0;
    long long int count = 1;
    long long int pos = max(lb, field[0].first);
    while (pos + d <= hb) {
        long long int np = pos + d;
        while (field[i].second < np) {
            i++;
            if(i >= m){
                return false;
            }
        }
        pos = max(np, field[i].first);
        count++;
        if(count == n){
            break;
        }
    }
    //cout << d << ' ' << count << endl;
    return count >= n;
}
int main(){
    freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
    long long int n, m, a, b;
    cin >> n >> m;
    vector<pair<long long int, long long int>> ends;
    long long int lb = INT64_MAX;
    long long int hb = -1;
    for(long long int i = 0; i < m; i++){
        cin >> a >> b;
        ends.push_back({a, b});
        lb = min(a, lb);
        hb = max(b, hb);
    }
    sort(ends.begin(), ends.end(), comparepair);
    long long int low = 0;
    long long int high = hb - lb;
    //cout << low << ' ' << high << endl;
    while(low < high){
        long long int mid = low + (high - low + 1) / 2;
        if(isPossible(n, m, ends, mid, lb, hb)){
            low = mid;
        }else{
            high = mid - 1;
        }
    }
    cout << low;
}