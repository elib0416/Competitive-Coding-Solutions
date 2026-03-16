#include <bits/stdc++.h>
using namespace std;
unsigned long long int n, p;
vector<unsigned long long int> machines;
bool f(unsigned long long int t){
    unsigned long long int total = 0;
    for(unsigned long long int x : machines){
        total += t / x;
    }
    //cout << t << ' ' << total << endl;
    return (total >= p);
}
int main(){
    cin >> n >> p;
    unsigned long long int k;
    for(unsigned long long int i = 0; i < n; i++){
        cin >> k;
        machines.push_back(k);
    }
    if(n == 1){
        cout << p * k;
        return 0;
    }
    unsigned long long int lo = 0;
    unsigned long long int hi = 1e17 + 1;
    while(lo < hi){
        unsigned long long int mid = lo + (hi - lo) / 2;
        if(f(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo;
}