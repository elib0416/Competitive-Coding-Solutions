#include <bits/stdc++.h>
using namespace std;
bool possible(int r, const vector<int>& arr, int m, int n){
    /*for(auto x : arr){
        cout << x << ' ';
    }
    cout << "check" << endl;*/
    /*if(lower_bound(arr.begin(), arr.end(), 36) == arr.end()){
        //cout << "check" << *lower_bound(arr.begin(), arr.end(), 36);
    }*/
    int pos = arr[0];
    int total = 0;
    while(pos <= arr[n - 1]){
        total++;
        if(total > m){
            return false;
        }
        //blow up pos + r;
        //cout << "BLOW UP" << pos + r << endl;
        auto it = lower_bound(arr.begin(), arr.end(), pos + 1 + 2 * r);
        if(it == arr.end()){
            //cout << "HERE";
            break;
        }else{
            pos = *it;
            //cout << "NEXT target is" << pos << endl;
        }
    }
    //cout << r << ' ' << total << endl;
    return total <= m;
}
int main(){
    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
         cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    /*for(auto x : arr){
        cout << x << ' ';
    }
    cout << endl;*/
    int dif = arr[n - 1] - arr[0];
    if(m == 1){
        if(dif % 2 == 0){
            cout << dif / 2;
        }else{
            cout << dif / 2 + 1;
        }
        return 0;
    }
    int lo = 1;
    int hi = dif / 2 + 1;
    while(lo < hi){
        //cout << "LOW AND HI " << lo << ' ' << hi << endl;
        int mid = lo + (hi - lo) / 2;
        if(possible(mid, arr, m, n)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}