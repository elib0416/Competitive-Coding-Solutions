#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <set>
#include <utility>
#include <cstdlib>
using namespace std;
void check(vector<set<string>>& string0, vector<set<string>>& string1, map<string, bool>& ok, map<string, int>& stuff, int n){
    bool good = false;
    for(int i = 0; i < n; i++){
        set<int> set1;
        for(string s : string0[i]){
            if(!ok[s]){
                set1.insert(stuff[s]);
            }
        }
        if(set1.size() == 1){
            good = true;
            for(string s : string0[i]){
                ok[s] = true;
            }
        }
        set<int> set2;
        for(string s : string1[i]){
            if(!ok[s]){
                set2.insert(stuff[s]);
            }
        }
        if(set2.size() == 1){
            good = true;
            for(string s : string1[i]){
                ok[s] = true;
            }
        }
    }
    if(good){
        check(string0, string1, ok, stuff, n);
    }
    return;
}
int main(){
    //freopen("main.in", "r", stdin);
    //freopen("main.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string verdict = "OK\n";
        int n, m;
        cin >> n >> m;
        //cout << n << ' ' << m << endl;
        vector<set<int>> arr0(n);
        vector<set<int>> arr1(n);
        vector<set<string>> string0(n);
        vector<set<string>> string1(n);
        map<string, int> stuff;
        set<string> everything;
        map<string, bool> ok;
        bool good = true;
        for(int i = 0; i < m; i++){
            string s;
            int a;
            cin >> s >> a;
            if(stuff[s] != 0 && stuff[s] != a + 1){
                good = false;
                break;
            }
            stuff[s] = a + 1;
            everything.insert(s);
            for(int j = 0; j < n; j++){
                if(s[j] - '0' == 0){
                    arr0[j].insert(a);
                    string0[j].insert(s);
                }else{
                    arr1[j].insert(a);
                    string1[j].insert(s);
                }
            }
        }
        if(!good){
            cout << "LIE\n";
            continue;
        }
        /*for(int i = 0; i < n; i++){
            if(arr0[i].size() == 1){
                cout << 0 << ' ' << i << endl;
                for(auto s : string0[i]){
                    ok[s] = true;
                }
            }
            if(arr1[i].size() == 1){
                cout << 1 << ' ' << i << endl;
                for(auto s : string1[i]){
                    ok[s] = true;
                }
            }
        }*/
        check(string0, string1, ok, stuff, n);
        for(auto s : everything){
            if(!ok[s]){
                verdict = "LIE\n";
                break;
            }
        }
        cout << verdict;
    }
}