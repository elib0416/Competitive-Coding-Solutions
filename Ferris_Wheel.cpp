#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, m;
    cin >> n >> m;
    vector<int> children(n);
    for(int i = 0; i < n; i++){
        cin >> children[i];
    }
    sort(children.begin(), children.end());
    int lo = 0;
    int hi = n - 1;
    int total = 0;
    int children_on = 0;
    while(lo < hi){
        if(children[lo] + children[hi] > m){
            hi--;
        }else{
            total++;
            children_on += 2;
            lo++;
            hi--;
        }
    }
    total += n - children_on;
    cout << total;
}