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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout); 
    int a, b, c, maximum = 0;
    cin >> a >> b >> c;
    for(int i = 0; i <= (c / b); i++){
        int left = c - (b * i);
        left %= a;
        maximum = max(maximum, c - left);
    }
    cout << maximum;
}