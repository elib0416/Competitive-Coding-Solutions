#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long a, b, ca, cb, f;
        cin >> a >> b >> ca >> cb >> f;
        long long amountexchanged = b / cb;
        a += amountexchanged * ca;
        if(a >= f){
            cout << 0 << endl;
            continue;
        }
        b = b % cb;
        long long ans = 0;
        long long amountneeded = f - a;
        ans = amountneeded;
        ans = max(ans, f - a - 1 + cb - b);
        long long amountofexchangesneeded = (amountneeded - 1) / ca + 1;
        ans = max(ans, cb - b + (amountofexchangesneeded - 1) * cb);
        long long leftovers = amountneeded % ca;
        if(leftovers == 0){
            leftovers = ca;
        }
        ans = max(ans, cb - b + (amountofexchangesneeded - 1) * cb + leftovers - 1);
        //ans = max(ans, cb - b + (amountofexchangesneeded - 2) * cb + leftovers - 1 + ca);
        cout << ans << endl;
    }
}