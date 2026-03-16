#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int minnum = 0, maxnum = 0;
	int curindex = 0;
	while (curindex < n) {
		if (s[curindex] == 'F') {
			curindex++;
			continue;
		}
		int nextindex = curindex + 1;
		while (nextindex < n && s[nextindex] == 'F'){
		    nextindex++;
		}
		if (nextindex == n){
		    break;
		}
		int numofF = nextindex - curindex - 1;
		if (s[nextindex] == s[curindex]) {
			int length = numofF + 2;
			if (length % 2 == 0) {
				minnum += 1;
			} else {
				minnum += 0;
			}
			maxnum += length - 1;
		} else {
			int length = numofF + 2;
			if (length % 2 == 0) {
				minnum += 0;
			} else {
				minnum += 1;
			}
			maxnum += length - 2;
		}
		curindex = nextindex;
	}
	int num_beginning_F = 0;
	while (num_beginning_F < n && s[num_beginning_F] == 'F'){
	    num_beginning_F++;
	}
	int num_ending_F = 0;
	while (num_ending_F < n && s[n - 1 - num_ending_F] == 'F'){
	    num_ending_F++;
	}
	if (num_beginning_F == n){
		minnum = 0;
		maxnum = n - 1;
	} else{
		maxnum += num_beginning_F;
		maxnum += num_ending_F;
	}
	vector<int> posibilities;
	if (num_beginning_F == 0 && num_ending_F == 0) {
		for(int i = minnum; i <= maxnum; i += 2){
		    posibilities.push_back(i);
		}
	} else{
		for(int i = minnum; i <= maxnum; i++){
		    posibilities.push_back(i);
		}
	}
	cout << posibilities.size() << endl;
	for (int i : posibilities){
	    cout << i << endl;
	}
}