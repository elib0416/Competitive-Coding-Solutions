#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout); 
    int n;
    string s, s1;
    cin >> n;
    vector<int> arr(26);
    for(int i = 0; i < n; i++){
        cin >> s >> s1;
        vector<int> left(26), right(26);
        for(char c : s){
            left[c - 'a']++;
        }
        for(char c : s1){
            right[c - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            arr[j] += max(left[j], right[j]);
        }
    }
    for(int x : arr){
        cout << x << endl;
    }
}