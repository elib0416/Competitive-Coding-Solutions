#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long double> position(n), speed(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        position[i] = static_cast<long double>(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        speed[i] = static_cast<long double>(x);
    }
    cout << fixed << showpoint << setprecision(8);
    long double lo = 0.0, hi = 1000000000.0;
    while(hi - lo >= 0.0000001){
        long double mid = lo + (hi - lo) / 2.0;
        long double low = 0.0;
        long double high = 1000000000.0;
        for(int i = 0; i < n; i++){
            low = max(low, position[i] - speed[i] * mid);
            high = min(high, position[i] + speed[i] * mid);
        }
        if(high < low){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << lo;
}