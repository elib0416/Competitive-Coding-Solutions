#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        set<string> st;
        for(int j = 0; j <= n - i; j++){
            st.insert(s.substr(j, i));
        }
        if(st.size() == n + 1 - i){
            cout << i;
            return 0;
        }
    }
}