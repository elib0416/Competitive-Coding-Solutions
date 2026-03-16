#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<longi long int> arr(m);
    vector<long long int> ppl(n);
    for(long long int i = 0; i < n; i++){
        cin >> ppl[i];
    }
    for(long long int i = 0; i < m; i++){
        cin >> arr[i];
    }
    sort(ppl.begin(), ppl.end());
    sort(arr.begin(), arr.end());
    for(int x : ppl){
        //cout << x << ' ';
    }
    long long int total = 0;
    int i, j = 0;
    while (i < n && j < m) {
		if (abs(ppl[i] - arr[j]) <= k) {
			++i;
			++j;
			++total;
		} else {
			if (ppl[i] - arr[j] > k) {
				++j;
			}
			else {
				++i;
			}
		}
    }
    cout << total;
}