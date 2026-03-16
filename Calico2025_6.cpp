#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "Oski\n";
        }else if(n % 3 == 0){
            cout << "Oski\n";
        }else{
            cout << "Big Ben\n";
        }
    }
}