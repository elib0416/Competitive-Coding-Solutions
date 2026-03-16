#include <bits/stdc++.h>
using namespace std; 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }
    auto check1 = [&](int l, int r){
        for(int i = l + 1; i <= r; i++)
            if(arr[i] != arr[i - 1])
                return false;
        return true;
    };
    auto check2 = [&](int l, int r){
        vector<pair<int, int>> blk;
        for(int i = l; i <= r; i++){
            if(blk.size() and arr[i] == arr[i - 1])
                blk.back().second++;
            else
                blk.push_back({arr[i], 1});
        }
        if(blk.size() <= 2 or blk.size() % 2 == 0){
            for(int i = 0; i + 2 < blk.size(); i++){
                if(blk[i] != blk[i + 2]){
                    return false;
                }
            }
            return true;
        }
        return false;
    };
    auto check3 = [&](int l, int r){
        for(int blkLen = 1; blkLen <= r - l + 1; blkLen++){
            if((r - l + 1) % blkLen){
                continue;
            }
            bool ok = true;
            for(int i = l; i + blkLen <= r; i++){
                ok &= (arr[i] == arr[i + blkLen]);
            }
            if(!ok){
                continue;
            }
            for(int i = l; i <= l + blkLen; i++)
                if((check1(l, i) and check2(i + 1, l + blkLen - 1)) or (check2(l, i) and check1(i + 1, l + blkLen - 1)))
                    return true;
        }
        return false;
    };
    if(k == 1){
        if(check1(0, n - 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else if (k == 2){
        if(check2(0, n - 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else{
        if(check3(0, n - 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}