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
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout); 
    int n, a;
    cin >> n;
    vector<int> to(n), cows(n), next(n), id(n);
    for(int i = 0; i < n; i++){
        cin >> a;
        a--;
        to[a] = i;
        //cout << to[i] << ' ';
    }
    //cout << endl;
    for(int i = 0; i < n; i++){
        cin >> id[i];
        //cout << id[i];
    }
    for(int i = 0; i < n; i++){
        cows[i] = i;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            next[to[j]] = cows[j];
        }
        /*for(int j = 0; j < n; j++){
            cout << next[j] << ' ';
        }
        cout << endl;*/
        cows = next;
    }
    for(int i = 0; i < n; i++){
        cout << id[cows[i]] << endl;
    }
}