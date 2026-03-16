#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int n, m;
	cin >> n >> m;
	vector<int> chickens(n);
	for(int i = 0; i < n; i++){
	    cin >> chickens[i];
	}
	sort(chickens.begin(), chickens.end());
	vector<pair<int, int>> cows(m);
	for(int i = 0; i < m; i++){
	    cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());
	int num = 0;
	int index = 0;
	priority_queue<int> cows2;
	for(int c : chickens){
		while(index < cows.size() && cows[index].first <= c){
			cows2.push(-cows[index].second);
			index++;
		}
		while(!cows2.empty() && -cows2.top() < c){
			cows2.pop();
		}
		if(!cows2.empty()){
			num++;
			cows2.pop();
		}
	}
	cout << num << endl;
}