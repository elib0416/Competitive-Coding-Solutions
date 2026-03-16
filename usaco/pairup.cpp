#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        arr.push_back({y, x});
    }
    sort(arr.begin(), arr.end());
    int maxtime = 0, left = 0, right = n - 1;
    while(left <= right){
        int mostpairs = min(arr[left].second, arr[right].second);
        if(left == right){
            mostpairs /= 2;
        }
        maxtime = max(maxtime, arr[left].first + arr[right].first);
        arr[left].second -= mostpairs;
        arr[right].second -= mostpairs;
        if (arr[left].second == 0){
            left++; 
        } 
		if (arr[right].second == 0){
		    right--;
		}
    }
    cout << maxtime;
}