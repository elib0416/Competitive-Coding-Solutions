#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int best = 1e9 + 7;
        for(int i = 0; i < static_cast<int>(s.size()) - 2; i++){
            if(s.substr(i, 3) == "MOO"){
                best = static_cast<int>(s.size()) - 3;
                break;
            }else if(s.substr(i, 3) == "MOM" || s.substr(i, 3) == "OOO"){
                best = min(best, static_cast<int>(s.size()) - 2);
            }else if(s.substr(i, 3) == "OOM"){
                best = min(best, static_cast<int>(s.size()) - 1);
            }
        }
        if(best == 1e9 + 7){
            cout << -1 << endl;
        }else{
            cout << best << endl;
        }
    }
}