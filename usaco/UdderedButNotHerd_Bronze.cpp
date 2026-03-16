#include <bits/stdc++.h>
using namespace std;
int main(){
    map<char, int> convert;
    for(int i = 0; i < 26; i++){
        char c;
        cin >> c;
        convert[c] = i;
    }
    string s;
    cin >> s;
    int size = s.size();
    int total = size;
    for(int i = 0; i < size - 1; i++){
        if(convert[s[i]] < convert[s[i + 1]]){
            total--;
        }
    }
    cout << total;
}