#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, m;
    cin >> n >> m;
    vector<long long int> cows(n);
    vector<long long int> canes(m), canebase(m, 1);
    for(long long int i = 0; i < n; i++){
        cin >> cows[i];
    }
    for(long long int i = 0; i < m; i++){
        cin >> canes[i];
    }
    for(long long int i = 0; i < m; i++){
        long long int index = 0;
        while(canes[i] > 0 && index < n){
            if(cows[index] >= canes[i]){
                cows[index] += canes[i] - canebase[i] + 1;
                break;
            }else if(cows[index] < canebase[i]){
                index++;
                continue;
            }else{
                long long int a = cows[index];
                cows[index] += a - canebase[i] + 1;
                canebase[i] = a + 1;
            }
            index++;
        }
    }
    for(long long int i = 0; i < n; i++){
        cout << cows[i] << endl;
    }
}