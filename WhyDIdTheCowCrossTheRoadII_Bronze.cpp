#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <set>
using namespace std;
bool intersect(int a, int b, int c, int d){
    return ((a < c && b > c && b < d) || (a > c && a < d && b > d));
}
int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<pair<int, int>> arr(26, {-1, 0});
    char c;
    for(int i = 0; i < 52; i++){
        cin >> c;
        int index = c - 'A';
        if(arr[index].first != -1){
            arr[index].second = i;
        }else{
            arr[index].first = i;
        }
    }
    int total = 0;
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 26; j++){
            int a = arr[i].first, b = arr[i].second, c = arr[j].first, d = arr[j].second;
            if(intersect(a, b, c, d)){
                total++;
            }
        }
    }
    cout << total;
}