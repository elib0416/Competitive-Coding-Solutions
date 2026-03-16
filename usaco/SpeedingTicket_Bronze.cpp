#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout); 
    int n, m, ans = 0, a, b;
    vector<int> limit(100), speed(100);
    cin >> n >> m;
    //cout << n << m << endl;
    int pos = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        //cout << a << ' ' << b << endl;
        for(int j = pos; j < pos + a; j++){
            limit[j] = b;
        }
        pos += a;
    }
    pos = 0;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        for(int j = pos; j < pos + a; j++){
            speed[j] = b;
        }
        pos += a;
    }
    /*for(int i = 0; i < 100; i++){
        cout << speed[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 100; i++){
        cout << limit[i] << ' ';
    }
    cout << endl;*/
    for(int i = 0; i < 100; i++){
        ans = max(ans, speed[i] - limit[i]);
    }
    cout << ans;
}