#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int a, b, c, ab, ac, bc, abc;
    vector<int> arr(7);
    for(int i = 0; i < 7; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    a = arr[0];
    b = arr[1];
    abc = arr[6];
    if(abc - a - b > a + b){
        c = arr[3];
    }else{
        c = arr[2];
    }
    cout << a << ' ' << b << ' ' << c;
}