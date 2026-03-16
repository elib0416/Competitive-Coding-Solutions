#include <bits/stdc++.h>
using namespace std;
bool less1(long long int x, long long int n){
    long long int sum = 0;
    for(int i = 1; i <= n; i++){
        //cout << x << "on row" << i << "adds" << min((x/i), n) << endl;
        sum += min((x/i), n);
    }
    //cout << x << "->" << sum << endl;
    return (sum >= (n * n + 1) / 2);
}
int main(){
    long long int n;
    cin >> n;
    long long int lo = 1;
    long long int hi = n * n;
    while(lo < hi){
        long long int mid = lo + (hi - lo) / 2;
        if(less1(mid, n)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}