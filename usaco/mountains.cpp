#include <bits/stdc++.h>
using namespace std;
struct peak{
    int x, y;
};
bool compare(const peak& A, const peak& B){
    return A.y > B.y;
}
int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    vector<peak> peaks(n);
    for(int i = 0; i < n; i++){
        cin >> peaks[i].x >> peaks[i].y;
    }
    sort(peaks.begin(), peaks.end(), compare);
    /*for(auto P : peaks){
        cout << P.x << ' ' << P.y << endl;
    }*/
    int total = 0;
    for(int i = 0; i < n; i++){
        total++;
        for(int j = 0; j < i; j++){
            if(abs(peaks[i].x - peaks[j].x) > peaks[j].y - peaks[i].y){
                continue;
            }else{
                //cout << i << ' ' << j << endl;
                total--;
                break;
            }
        }
    }
    cout << total;
}