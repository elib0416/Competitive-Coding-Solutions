#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q, a, b;
    cin >> n;
    vector<int> arr(n);
    map<int, int> index;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        index[arr[i]] = i;
    }
    /*for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    for(auto P : index){
        cout << P.first << ' ' << P.second << endl;
    }*/
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        swap(arr[index[a]], arr[index[b]]);
        swap(index[a], index[b]);
        /*for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;*/
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
}
/*5 1 3 7 4 2 6
5 1 3 6 4 2 7
2 1 3 6 4 5 7
2 1 5 6 4 3 7
*/