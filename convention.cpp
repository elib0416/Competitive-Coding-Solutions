#include <bits/stdc++.h>
using namespace std;
bool possible(const vector<int>& arr, int n, int m, int c, int t) {
    vector<int> cows = arr;
    /*for(int x : arr){
        cout << x << ' ';
    }
    cout << endl;*/
    int index = 0;
    int cur_cows = 0;
    int total = 0;
    int base = -1;
    while(index < n){
        //cout << t << ' ' << index << endl;
        total++;
        if(total > m){
            //cout << t << ' ' << total << endl;
            return false;
        }
        cur_cows = 1;
        base = cows[index];
        //cout << "base = " << base << endl;
        index++;
        //cout << "next one is " << cows[index] << endl;
        //cout << (cows[index] - base <= t) << endl;
        while(cur_cows < c && index < n){
            if(cows[index] - base <= t){
                //cout << "index " << index << ' ' << cur_cows << endl;
                cur_cows++;
                index++;
            }else{
                break;
            }
        }
    }
    //cout << t << ' ' << total << endl;
    return total <= m;
}

int main(){
    freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
         cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if(c == 1){
        cout << arr[n - 1] - arr[0];
        //cout << "h";
        return 0;
    }
    int lo = 0;
    int hi = arr[n - 1] - arr[0];
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(possible(arr, n, m, c, mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}