#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k, cursum = 0;
    string s = "";
    cin >> n >> k;
    vector<string> essay(n);
    vector<int> length(n);
    vector<string> newessay;
    for(int i = 0; i < n; i++){
        cin >> essay[i];
        length[i] = essay[i].length();
    }
    /*for(int i = 0; i < n; i++){
        cout << essay[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << length[i] << ' ';
    }
    cout << endl;*/
    for(int i = 0; i < n; i++){
        if(cursum + length[i] <= k){
            //cout << "here";
            cursum += length[i];
            if(i == 0){
                s += essay[i];
                continue;
            }
            s += ' ' + essay[i];
        }else{
            newessay.push_back(s);
            s = essay[i];
            cursum = length[i];
        }
    }
    if(s != ""){
        newessay.push_back(s);
    }
    for(string str : newessay){
        cout << str << endl;
    }
}