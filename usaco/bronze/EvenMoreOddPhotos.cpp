#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] % 2){
            odd++;
        }else{
            even++;
        }
    }
    int num = 0;
    while(odd > 0 || even > 0){
        if(num % 2 == 0){
            if(odd < 2 && even <= 0){
                cout << num - 1;
                //cout << "made a mistake, take the odd number and put and the group before and combine with the group before both of them" << endl;
                return 0;
            }else if(even != 0){
                even--;
                //cout << "put one even into an even group" << endl;
            }else{
                odd -= 2;
                //cout << "put two odds into an even group" << endl;
            }
        }else{
            if(odd == 0 && even == 0){
                cout << num;
                return 0;
            }else if(odd == 0 && even > 0){
                cout << num;
                return 0;
            }else{
                odd--;
            }
        }
        num++;
    }
    cout << num;
}