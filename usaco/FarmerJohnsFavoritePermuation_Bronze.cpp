#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    if(arr[n - 2] != 1){
        cout << -1 << endl;
        return;
    }
    /*if(n == 2){
        cout << "1 2" << endl;
        return;
    }*/
    vector<int> seen(n + 1);
    for(int i = 0; i < n - 1; i++){
        seen[arr[i]] = true;
    }
    vector<int> permutation(n);
    vector<int> donthave;
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            donthave.push_back(i);
        }
    }
    int num1 = count(arr.begin(), arr.end(), 1);
    if(donthave.size() > 2 || arr.back() != 1 || (donthave.size() == 2 && num1 != 2)){
		cout << -1 << endl;
		return;
	}
	if(donthave.size() == 1){
	    permutation[0] = 1;
	    permutation[n - 1] = donthave[0];
	}else{
	    permutation[0] = donthave[0];
	    permutation[n - 1] = donthave[1];
	}
    int lo = 0;
    int hi = n - 1;
    for(int i = 0; i < n - 1; i++){
        if(permutation[lo] > permutation[hi]){
            permutation[++lo] = arr[i];
        }else{
            permutation[--hi] = arr[i];
        }
    }
    /*vector<int> actualseen(n, false);
    for(int x : permutation){
        actualseen[x - 1] = true;
    }
    for(bool b : actualseen){
        if(!b){
            cout << -1 << endl;
            return;
        }
    }*/
    for(int i = 0; i < n - 1; i++){
        cout << permutation[i] << ' ';
    }
    cout << permutation[n - 1];
    cout << endl;
}  
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
