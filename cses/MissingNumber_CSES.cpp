#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    long long int n, a, total;
    cin >> n;
    total = (n * (n + 1)) / 2;
    for(int i = 0; i < n - 1; i++){
        cin >> a;
        total -= a;
    }
    cout << total;
}