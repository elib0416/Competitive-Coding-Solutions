#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "we got ";
        string s;
        string d;
        getline(cin, d);
        getline(cin, s);
        int a, b, c;
        cin >> a >> b >> c;
        if(a < 2026){
            cout << s << "before gta6" << endl;
            continue;
        }else if(a == 2026 && b < 11){
            cout << s << "before gta6" << endl;
            continue;
        }else if(a == 2026 && b == 11 && c < 19){
            cout << s << "before gta6" << endl;
            continue;
        }else{
            cout << "gta6 before " << s << endl;
        }
    }
}