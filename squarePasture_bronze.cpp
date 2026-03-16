#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1, x2, x3, x4, y1, y2, y3, y4, minx, maxx, miny, maxy, mindis;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cout << max((max(x2, x4) - min(x1, x3)), (max(y2, y4) - min(y1, y3))) * max((max(x2, x4) - min(x1, x3)), (max(y2, y4) - min(y1, y3)));
}