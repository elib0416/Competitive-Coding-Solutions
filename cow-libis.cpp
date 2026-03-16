#include <bits/stdc++.h>
using namespace std;
struct alibi{
    long long int x, y, t;
};
bool compare(alibi& a, alibi& b){
    return a.t < b.t;
}
bool comparevalue(alibi& a, long long int value){
    return a.t < value;
}
double dis(long long int x, long long int y, long long int tx, long long int ty){
    //cout << ((x - tx) * (x - tx)) << ' ' << ((y - ty) * (y - ty)) << endl;
    return ((x - tx) * (x - tx)) + ((y - ty) * (y - ty));
}
int main(){
    long long int n, q;
    cin >> n >> q;
    vector<alibi> alibis;
    long long int x, y, t;
    for(long long int i = 0; i < n; i++){
        cin >> x >> y >> t;
        alibis.push_back({x, y, t});
    }
    sort(alibis.begin(), alibis.end(), compare);
    /*for(alibi current : alibis){
        cout << current.x << ' ' << current.y << ' ' << current.t << endl;
    }*/
    long long int innocent = 0;
    for (long long int i = 0; i < q; i++){
        cin >> x >> y >> t;
        auto lower = lower_bound(alibis.begin(), alibis.end(), t, comparevalue);
        long long int index;
        alibi current;
        if(lower == alibis.begin()){
            if(lower->t > t){
                index = -1;
            }else{
                index = 0;
            }
        }else if(lower == alibis.end()){
            index = n - 1;
        }else if(lower->t == t){
        }else{
            index--;
        }
        if(index >= 0){
            current = alibis[index];
            if(dis(x, y, current.x, current.y) > (t - current.t) * (t - current.t)){
                innocent++;
                continue;
            }
        }
        if(index < n - 1){
            current = alibis[++index];
            if(dis(x, y, current.x, current.y) > (t - current.t) * (t - current.t)){
                innocent++;
                continue;
            }
        }
    }
    cout /*<< "i" */<<  innocent;
}