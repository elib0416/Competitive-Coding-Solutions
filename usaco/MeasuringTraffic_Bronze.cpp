#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
struct segment{
    string str;
    int x, y;
};
int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout); 
    int n, a, b, lo = -1e6, hi = 1e6;
    string s;
    cin >> n;
    vector<segment> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].str >> arr[i].x >> arr[i].y;
    }
    for(int i = n - 1; i >= 0; i--){
        auto current = arr[i];
        //cout << current.str << endl;
        if(current.str == "off"){
            lo += current.x;
            hi += current.y;
        }else if(current.str == "none"){
            lo = max(lo, current.x);
            hi = min(hi, current.y);
        }else if(current.str == "on"){
            lo -= current.y;
            hi -= current.x;
        }
    }
    cout << max(0, lo) << ' ' << hi << endl;
    lo = -1e6;
    hi = 1e6;
    for(int i = 0; i < n; i++){
        auto current = arr[i];
        if(current.str == "on"){
            lo += current.x;
            hi += current.y;
        }else if(current.str == "none"){
            lo = max(current.x, lo);
            hi = min(current.y, hi);
        }else if(current.str == "off"){
            lo -= current.y;
            hi -= current.x;
        }
    }
    cout << max(0, lo) << ' ' << hi;
}