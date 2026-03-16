#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n, k, total = 0;
    cin >> n;
    int gamelength = n / 2;
    vector<int> arrlow, arrhigh;
    vector<int> other_cowstart, other_cowend;
    vector<bool> isinother_cow(2 * n + 1);
    for(int i = 0; i < gamelength; i++){
        cin >> k;
        other_cowstart.push_back(k);
        isinother_cow[k] = true;
    }
    for(int i = 0; i < gamelength; i++){
        cin >> k;
        other_cowend.push_back(k);
        isinother_cow[k] = true;
    }
    int num = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(!isinother_cow[i]){
            if(num < gamelength){
                arrlow.push_back(i);
            }else{
                arrhigh.push_back(i);
            }
            num++;
        }
    }
    //sort(arr.begin(), arr.end());
    sort(other_cowstart.begin(), other_cowstart.end());
    sort(other_cowend.begin(), other_cowend.end());
    /*for(auto x : arr){
        cout << x << ' ';
    }
    cout << endl;
    for(auto x : other_cow){
        cout << x << ' ';
    }
    cout << endl;*/
    int index;
    for(auto x : other_cowstart){
        auto it = lower_bound(arrhigh.begin(), arrhigh.end(), x);
        if(it != arrhigh.end()){
            total++;
            arrhigh.erase(it);
        }
    }
    for(auto x : other_cowend){
        auto it = lower_bound(arrlow.begin(), arrlow.end(), x);
        if(it != arrlow.begin()){
            if(it == arrlow.end()){
                it = arrlow.begin() + 1;
            }
            it--;
            total++;
            arrlow.erase(it);
        }
    }
    cout << total;
}