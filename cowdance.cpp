#include <bits/stdc++.h>
using namespace std;
bool possible(const vector<int>& arr, int n, int m, int k) {
    vector<int> stage;  // stores finish times of cows currently on stage

    for (int i = 0; i < n; i++) {
        if ((int)stage.size() < k) {
            // Stage has free slots; place cow directly
            stage.push_back(arr[i]);
        } else {
            // Stage is full; find the earliest available slot
            int earliest = *min_element(stage.begin(), stage.end());
            // Remove that finished time and assign new cow to it
            int idx = min_element(stage.begin(), stage.end()) - stage.begin();
            stage[idx] = earliest + arr[i];
        }
    }

    // Final time is the latest cow finish
    int total_time = *max_element(stage.begin(), stage.end());
    return total_time <= m;
}

int main(){
    freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
         cin >> arr[i];
    }
    int dif = arr[n - 1] - arr[0];
    if(accumulate(arr.begin(), arr.end(), 0) < m){
        cout << 1;
        return 0;
    }
    int lo = 2;
    int hi = n;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(possible(arr, n, m, mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}