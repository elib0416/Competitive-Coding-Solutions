#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, x2, x3, x4, y1, y2, y3, y4, minx = 2002, maxx = -1, miny = 2002, maxy = -1;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int num = 0;
    if(x1 >= x3 && x1 <= x4 && y1 >= y3 && y1 <= y4){
        num++;
    }
    if(x1 >= x3 && x1 <= x4 && y2 >= y3 && y2 <= y4){
        num++;
    }
    if(x2 >= x3 && x2 <= x4 && y1 >= y3 && y1 <= y4){
        num++;
    }
    if(x2 >= x3 && x2 <= x4 && y2 >= y3 && y2 <= y4){
        num++;
    }
    if(num < 2){
        cout << ((y2 - y1) * (x2 - x1));
    }else if(num == 4){
        cout << 0;
    }else{
        cout << ((y2 - y1) * (x2 - x1)) - ((min(x2, x4) - max(x1, x3)) * (min(y2, y4) - max(y1, y3)));
    }
}