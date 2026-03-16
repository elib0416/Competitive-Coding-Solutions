#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;
int n, k;
int main()
{
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    cin >> n >> k;
    vector<int> diff(n);
    vector<int> p(n);
    int x, y;
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        diff[x]++;
        diff[y + 1]--;
    }
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + diff[i];
    }
    
    sort(p.begin(), p.end());
    cout << endl;
    cout << p[n/2];
    return 0;
}
