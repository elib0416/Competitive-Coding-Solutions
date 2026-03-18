#include <bits/stdc++.h>
using namespace std;
long long numinversions(int x, int y, const vector<int>& arr){
    long long t = 0;
    int number = 0;
    for(int i = x; i <= y; i++){
        if(arr[i] == 1){
            number++;
        }else{
            t += number;
        }
    }
    return t;
}
void solve(int n, const vector<int>& arr, int ones, long long target, long long direction, long long& best){
    long long inversion0 = numinversions(0, n - 1, arr);
    long long inversion1 = numinversions(n, 2 * n - 1, arr);
    long long d = inversion0 - inversion1;
    int j = n;
    best = min(best, abs(d));
    int number = 0;
    int displaced = 0;
    long long cost = 0;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] == target){
            d -= direction * (n - 1 - i);
            cost += (n - 1 - i);
            d += direction * (ones - n);
            cost++;
            d += direction * number;
            cost += number;
            d += direction * displaced;
            cost += displaced;
            number++;
            if(number + displaced > n){
                return;
            }
            while(number + displaced > j - n){
                if(arr[j] == 1 - target){
                    j++;
                }else if (j == 2 * n - 1){
                    return;
                }else{
                    d += direction * (n + number + displaced - j);
                    cost += (n + number + displaced - j);
                    displaced++;
                    j++;
                }
            }
            best = min(best, cost + abs(d));
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    int ones = 0;
    for (int i = 0; i < 2 * n; i++){
        cin >> arr[i];
        ones += arr[i];
    }
    long long best = static_cast<long long>(1e18 + 7);
    solve(n, arr, ones, 1, 1, best);
    solve(n, arr, ones, 0, -1, best);
    cout << best;
}
