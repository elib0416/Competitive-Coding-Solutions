#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
//#include <string>
using namespace std;
string censor(string& s, string& t, int start){
    int n = s.length();
    int m = t.length();
    for(int i = start; i < n - m; i++){
        string str = s.substr(i, m);
        if(str == t){
            s.erase(i, m);
            //cout << s[0] << endl;
            return censor(s, t, max(0, i - m + 1));
        }
    }
    //cout << s;
    return s;
}
int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, t;
    int n, m;
    cin >> s;
    cin >> t;
    n = s.length();
    m = t.length();
    //cout << s << ' ' << t << ' ' << n << ' ' << m << endl;
    cout << censor(s, t, 0);
    //cout << 1;
}