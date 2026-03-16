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
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout); 
    int x, y;
    cin >> x >> y;
    //cout << x << ' ' << y;
    int pos = x, target;
    int dis = 0;
    int i = 0;
    while(true){
        if(i % 2 == 0){
            target = x + (1 << i);
            if(target >= y && y >= x){
                dis += y - pos;
                //cout << i << ' ';
                cout << dis;
                return 0;
            }else{
                dis += target - pos;
            }
            pos = target;
        }else{
            target = x - (1 << i);
            if(target <= y && y <= x){
                dis += pos - y;
                //cout << i << ' ';
                cout << dis;
                return 0;
            }else{
                dis += pos - target;
            }
            pos = target;
        }
        i++;
    }
}