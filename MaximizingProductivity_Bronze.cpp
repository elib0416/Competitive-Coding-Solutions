#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> mustwake(n);
    for(int i = 0; i < n; i++){
        cin >> mustwake[i];
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mustwake[i] -= a + 1;
    }
    sort(mustwake.begin(), mustwake.end(), greater<int>());
    while(q--){
        int a, b;
        cin >> a >> b;
        if(mustwake[a - 1] >= b){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}