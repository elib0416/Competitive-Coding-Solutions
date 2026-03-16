#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <set>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int numtargets = 0;
    vector<int> bounce(n, -1), target(n, -1);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a){
            target[i] = b;
            numtargets++;
        }else{
            bounce[i] = b;
        }
    }
    int total = 0;
    int p = 1;
    int dir = 1;
    int pos = m - 1;
    while(total < numtargets && pos >= 0 && pos < n){
        if(bounce[pos] != -1){
            dir *= -1;
            p += bounce[pos];
            pos += p * dir;
        }else{
            if(target[pos] != -1 && target[pos] <= p){
                total++;
                target[pos] = -1;
            }
            pos += p * dir;
        }
    }
    cout << total;
}