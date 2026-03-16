#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
int n, m;
vector<long long int> arr;
bool possible(int number){
    int total = 0;
    int cur_sum = 0;
    for(long long int x : arr){
        if (total > m){
            return false;
        }
        if(x > number){
            return false;
        }else if(cur_sum + x > number){
            total++;
            cur_sum = 0;
        }
        cur_sum += x;
    }
    if(cur_sum > 0){
        total++;
    }
    //cout << number << ' ' << total << endl;
    return (total <= m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    long long int k;
    for(int i = 0; i < n; i++){
        cin >> k;
        arr.push_back(k);
    }
    if(m == 1){
        long long int sum = 0;
        for(long long int x : arr){
            sum += x;
        }
        cout << sum;
        return 0;
    }
    long long int lo = *max_element(arr.begin(), arr.end());
    long long int hi = accumulate(arr.begin(), arr.end(), 0LL);
    while(lo < hi){
        int mid = (hi + lo) / 2;
        if(possible(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}