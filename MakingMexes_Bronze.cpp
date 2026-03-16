/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    cin >> n;
    vector<int> arr(n + 1), missing(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a]++;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i - 1] == 0){
            missing[i] = missing[i - 1] + 1;
        }else{
            missing[i] = missing[i - 1];
        }
    }
    for(int i = 0; i <= n; i++){
        cout << max(arr[i], missing[i]) << endl;
    }
}