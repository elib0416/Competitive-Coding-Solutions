#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n), G, H;
    vector<int> list(n);
    int firstg = 1e9, firsth = 1e9, lastg = 0, lasth = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'G'){
            arr[i] = 0;
            G.push_back(i);
            firstg = min(firstg, i);
            lastg = i;
            //cout << i << endl;
        }else{
            arr[i] = 1;
            firsth = min(firsth, i);
            lasth = i;
            H.push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        cin >> list[i];
    }
    int num = 0;
    bool gleader = false, hleader = false;
    if(list[firstg] > lastg){
        gleader = true;
    }
    if(list[firsth] > lasth){
        hleader = true;
    }
    if(gleader && hleader){
        num++;
    }
    /*for(int i = 0; i < H.size(); i++){
        cout << H[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < G.size(); i++){
        cout << G[i] << ' ';
    }
    cout << endl;
    */
    //cout << gleader << ' ' << hleader << ' ' << firstg << ' ' << firsth << ' ' << lastg << ' ' << lasth << endl;
    if(gleader){
        for(int i = 0; i < H.size(); i++){
            if(i == 0 && hleader){
                continue;
            }
            if(H[i] < firstg && list[H[i]] > firstg){
                num++;
            }
        }
    }
    if(hleader){
        for(int i = 0; i < G.size(); i++){
            if(i == 0 && gleader){
                continue;
            }
            if(G[i] < firsth && list[G[i]] > firsth){
                num++;
            }
        }
    }
    cout << num;
}