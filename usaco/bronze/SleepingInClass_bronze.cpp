#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> p(n + 1, 0);
    int maximum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        p[i + 1] = p[i] + arr[i];
        maximum = max(maximum, arr[i]);
    }
    int sum = p[n];
    if(sum == maximum * n){
        cout << 0 << endl;
        return;
    }
    //cout << maximum << endl;
    for(int i = 1; i < n; i++){
        if(p[i] == 0){
            continue;
        }
        if(sum % p[i] == 0 && maximum <= p[i]){
            int unit = p[i];
            int bottom = i;
            int index = bottom + 1;
            /*if(i == 2){
                cout << unit << ' ' << bottom << endl;
            }*/
            bool good = false;
            while(bottom <= n && index <= n){
                //cout << ".";
                /*if(index == 6){
                    cout << p[index] - p[bottom] << endl;
                }*/
                if(p[index] - p[bottom] == unit){
                    good = true;
                    if(index == n){
                        break;
                    }
                    bottom = index;
                    index++;
                    /*if(i == 2){
                        cout << bottom << ' ' << unit << endl;
                    }*/
                }else if(p[index] - p[bottom] > unit){
                    /*if(i == 2){
                        cout << "NOOO " << p[index] << ' ' << index << endl;
                    }*/
                    good = false;
                    break;
                }else{
                    index++;
                    good = false;
                }
            }
            if(good){
                cout << n - (sum / unit) << endl;
                return;
            }
        }
    }
    cout << n - 1 << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}