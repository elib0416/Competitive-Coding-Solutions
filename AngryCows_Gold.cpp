#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> haybales(n);
    for(long long i = 0; i < n; i++){
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());
    vector<long long> left(n, 1e9 + 7), right(n, 1e9 + 7);
    long long i = 1, j = 0;
    left[0] = 0;
    while(i < n){
        while(j + 1 < i && max(left[j + 1] + 1, haybales[i] - haybales[j + 1]) <= max(left[j] + 1, haybales[i] - haybales[j])){
            j++;
        }
        left[i] = max(haybales[i] - haybales[j], left[j] + 1);
        i++;
    }
    i = n - 2;
    j = n - 1;
    right[n - 1] = 0;
    while(i >= 0){
        //max(haybales[i] - haybales[j], left[j] + 1)*/
        while (j - 1 > i && max(right[j - 1] + 1, haybales[j - 1] - haybales[i]) <= max(right[j] + 1, haybales[j] - haybales[i])){
            j--;
        }
        right[i] = max(haybales[j] - haybales[i], right[j] + 1);
        i--;
    }
    /*for(long long i = 0; i < n; i++){
        cout << left[i] << ' ';
    }
    cout << endl;
    for(long long i = 0; i < n; i++){
        cout << right[i] << ' ';
    }
    cout << endl*/
    i = 0;
    double ans = 1e9 + 7;
    for(int i = 0; i < n; i++){
        ans = min(ans, static_cast<double>(max(left[i], right[i])));
        if(i != n - 1){
            double cost1 = max(left[i], right[i + 1]) + 1;
            double cost2 = static_cast<double>(static_cast<double>(haybales[i + 1] - haybales[i]) / 2.0);
            ans = min(ans, max(cost1, cost2));
        }
    }
    int x = floor(ans);
    if(x == ans){
        cout << x << ".0";
    }else{
        cout << x << ".5";
    }
}