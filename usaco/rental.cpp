#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> cows(n);
	vector<pair<int, int>> shops(m);
	vector<int> rent(r);
	for (int i = 0; i < n; i++){
	    cin >> cows[i];
	}
	for (int i = 0; i < m; i++) {
	    cin >> shops[i].second >> shops[i].first;
	}
	for (int i = 0; i < r; i++){
	    cin >> rent[i];
	}
	sort(cows.begin(), cows.end(), greater<int>());
	sort(shops.begin(), shops.end(), greater<pair<int, int>>());
	sort(rent.begin(), rent.end(), greater<int>());
	int shoppos = 0;
	int farmerpos = 0;
	int pos = 0;
	long long most_money = 0;
	while (pos < n) {
		int milk = cows[pos];
		int shopprofits = 0;
		int curr_shop = shoppos;
		int last = 0;
		while (curr_shop < m) {
			int sold = min(milk, shops[curr_shop].second);
			shopprofits += shops[curr_shop].first * sold;
			milk -= sold;
			if (milk == 0) {
				last = sold;
				break;
			} else {
				curr_shop++;
			}
		}
		if (farmerpos >= r || shopprofits > rent[farmerpos]) {
		    //cout << "at pos " << pos << " we make " << shopprofits <<" instead of " << rent[farmerpos] << endl;
			most_money += shopprofits;
			shoppos = curr_shop;
			if (shoppos < m){
			    shops[shoppos].second -= last;
			}
			pos++;
		}else{
		    //cout << "rent the worst cow instead for " << rent[farmerpos] << endl;
			most_money += rent[farmerpos];
			n--;
			farmerpos++;
		}
	}
	cout << most_money << endl;
}