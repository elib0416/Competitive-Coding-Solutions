#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        double n;
        cin >> n;
        double rec = 1.0/n;
        int num = static_cast<int>(floor(rec));
        for(int i = 0; i < num; i++){
            cout << "REACT" << endl;
        }
        cout << "NEXT" << endl;
    }
}