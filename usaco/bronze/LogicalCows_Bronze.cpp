#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
	    cin >> s[i];
	}
	vector<int> section(n);
	int sectionindex = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == "or"){
			sectionindex++;
		}else{
			if(i % 2 == 0){
				section[i] = sectionindex;
			}
		}
	}
	vector<int> first_false(sectionindex + 1, 1e9);
	vector<int> last_false(sectionindex + 1, -1);
	for(int i = 0; i < n; i += 2){
		int sec = section[i];
		if(s[i] == "false"){
			if(first_false[sec] == 1e9){
				first_false[sec] = i;
			}
			last_false[sec] = i;
		}
	}
	int overallfirsttrue = 1e9, overalllasttrue = -1;
	for(int i = 0; i <= sectionindex; i++){
		if(first_false[i] == 1e9){
			if(overallfirsttrue == 1e9){
				overallfirsttrue = i;
			}
			overalllasttrue = i;
		}
	}
	while(m--){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		string t;
		cin >> t;
		int section1 = section[l], section2 = section[r];
		if(overallfirsttrue < section1 || overalllasttrue > section2){
			if(t == "true"){
			    cout << "Y";
			}else{
			    cout << "N";
			}
			continue;
		}
		if(t == "true"){
			if(first_false[section1] < l || last_false[section2] > r){
			    cout << "N";
			}else{
			    cout << "Y";
			}
		}
		else{
			cout << 'Y';
		}
	}
}