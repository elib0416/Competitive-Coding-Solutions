#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;
int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    map<string, map<string, bool>> hascharacteristics;
    map<string, vector<string>> characteristics;
    //map<string, int> index;
    vector<string> arr(n);
    set<string> characs;
    string s, str;
    int a;
    int num = 0;
    for(int i = 0; i < n; i++){
        cin >> s >> a;
        arr[i] = s;
        for(int j = 0; j < a; j++){
            cin >> str;
            characs.insert(str);
            characteristics[s].push_back(str);
            hascharacteristics[s][str] = true;
        }
    }
    /*for(string st : arr){
        cout << st;
        for(string str : characteristics[st]){
            cout << ' ' << str;
        }
        cout << endl;
    }*/
    int maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            string s1 = arr[i], s2 = arr[j];
            int num = 0;
            for(string str : characteristics[s1]){
                if(hascharacteristics[s2][str]){
                    num++;
                }
            }
            //cout << i << ' ' << j << ' ' << num << endl;
            maxi = max(maxi, num + 1);
        }
    }
    cout << maxi;
}