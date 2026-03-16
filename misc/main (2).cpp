#include <bits/stdc++.h>
using namespace std;
double p[200000];
int a[200000];
int intervals[200001];
int roundt(double z){
    z*= 100;
    int k = round(z);
    return k;
}
int main(){
    int t, n, q, k, c, z, u, v, y;
    double total;
    cin >> t;
    intervals[0] = 0;
    for(int b = 0; b < t; b++){
        total = 0;
        cin >> n >> q;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n; i++){
            cin >> a[i];
            intervals[i + 1] = intervals[i] + a[i];
        }
        for(int i = 0; i < q; i++){
            total = 0;
            cin >> k;
            for(int j = 1; j <= n; j++){
                if(k < intervals[j]){
                    c = j - 1;
                    break;
                }
            }
            for(int j = 0; j < c; j++){
                total+= p[j] * a[j];
            }
            z = k - intervals[c];
            total += p[c] * z;
            y = roundt(total);
            u = y % 100;
            v = y / 100;
            if(u >= 10){
                cout << v << '.' << u << endl;
            }else{
                cout << v << ".0" << u << endl;
            }
        }
    }
}