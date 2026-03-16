#include <bits/stdc++.h>
using namespace std;
struct cow{
    long long int x, depth;
};
long long int dfs(long long int a, long long int b){
    if(a == b){
        return  0;
    }else if(a > b){
        long long int mod = a % 2;
        return (mod + dfs((a + mod) / 2, b) + 1);
    }else{
        long long int mod = b % 2;
        return min(b - a, (mod + dfs(a, b / 2) + 1));
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        long long int a, b, op;
        cin >> a >> b;
        cout << dfs(a, b) << endl;
    }
}