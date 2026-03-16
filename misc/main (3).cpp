#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        p = k / 64;
        if(k % 64 != 0){
            p++;
        }
        if (p >= 64){
            cout << 64 << endl;
        }else{
            cout << p << endl;
        }
    }
}