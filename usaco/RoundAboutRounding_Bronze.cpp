#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int lb = 5;
        int up = 49;
        int ans = 0;
        int tenpower = 1;
        while(tenpower < 1e8) {
            tenpower *= 10;
            lb += 4 * tenpower;
            up = 5 * tenpower - 1;
            ans += max(0, min(up, n) - max(lb, 2) + 1);
            //cout << max(0, min(up, n) - max(lb, 2) + 1);
        }
        cout << ans << endl;
    }
}