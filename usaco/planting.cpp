#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int main(){
    int n, a, b;
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> n;
    vector<int> numadj(n);
    int ma = 0;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        numadj[a]++;
        numadj[b]++;
        ma = max(ma, max(numadj[a], numadj[b]));
    }
    cout << ma + 1;
}