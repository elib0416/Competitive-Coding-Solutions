#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int solve(){
    if (arr[n - 2] - arr[0] == n - 2 && arr[n - 1] - arr[n - 2] != 2) {
        return 2;
    }
    if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] != 2) {
        return 2;
    }
    int j = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        while (j < n - 1 && arr[j + 1] - arr[i] <= n - 1) {
            j++;
        }
        best = max(best, j - i + 1);
    }
    return n - best;
}

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int answer_min = solve();
    int gap_left = arr[n - 2] - arr[0];
    int gap_right = arr[n - 1] - arr[1];
    int answer_max = max(gap_left, gap_right) - (n - 2);
    cout << answer_min << endl << answer_max << endl;
    return 0;
}
 