#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for(long long int ii = 0; ii < n; ii++){
        cin >> arr[ii];
    }
    long long int q;
    cin >> q;
    while(q--){
        long long int i, v, t;
        cin >> i >> v >> t;
        //cout << i << ' ' << v << ' ' << t << endl;
        i--;
        arr[i] = v;
        vector<pair<long long int, long long int>> dumps(n);
        dumps[0] = {arr[0] + 1, arr[0] + 1};
        /*for(long long int x : arr){
            cout << x << ' ';
        }
        cout << endl;*/
        for(long long int j = 1; j < n; j++){
            long long int numberoftimes = (arr[j] - 1) / arr[j - 1] + 1;
            //cout << arr[j] << ' ' << arr[j - 1] << ' ' << numberoftimes << endl;
            dumps[j] = {dumps[j - 1].first + (numberoftimes - 1) * dumps[j - 1].second + 1, numberoftimes * (dumps[j - 1].second)};
        }
        for(auto [x, y] : dumps){
            //cout << x << ' ' << y << endl;
        }
        if(t < dumps[n - 1].first){
            cout << 0 << endl;
        }else{
            cout << ((1 + ((t - dumps[n - 1].first) / dumps[n - 1].second)) * arr[n - 1]) << endl;
        }
    }
}