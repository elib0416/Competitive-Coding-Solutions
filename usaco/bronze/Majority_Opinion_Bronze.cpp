#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        set<int> cando;
        vector<vector<int>> positions(n + 1);
        set<int> numbers;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            numbers.insert(arr[i]);
            if(i != 0 && arr[i] == arr[i - 1]){
                cando.insert(arr[i]);
            }
            if(i >= 2 && arr[i] == arr[i - 2]){
                cando.insert(arr[i]);
            }
            positions[arr[i]].push_back(i);
        }
        /*for(int x : numbers){
            if(cando.find(x) == cando.end()){
                for(int i = 0; i < positions[x].size(); i++){
                    bool ok = false;
                    for(int j = 1; j < positions[x].size(); j++){
                        if(2 * (j + 1 + i) > positions[x][j] - positions[x][i] + 1){
                            cando.insert(x);
                            ok = true;
                            break;
                        }
                    }
                    if(ok){
                        break;
                    }
                }
            }
        }*/
        if(cando.empty()){
            cout << -1 << endl;
        }else{
            bool osjflkds = true;
            for(int x : cando){
                if(osjflkds){
                    cout << x;
                    osjflkds = false;
                }else{
                    cout << ' ' << x;
                }
            }
            cout << endl;
        }
    }
}