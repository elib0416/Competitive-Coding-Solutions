#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string sub;
    for(int i = 0; i < n - 3;i++){
        sub = s.substr(i, 4);
        if(sub == "SSSS"){
            cout << "DIE";
            return 0;
        }
    }
    cout << "BEAT";
    return 0;
}