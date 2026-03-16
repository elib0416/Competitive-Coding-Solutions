#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, maxl = 0;
int ph[100001], pp[100001], ps[100001] = {0};
const char chars[3] = {'H', 'P', 'S'};
int main(){
    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	cin >> n;
	char c;
	for(int i = 1; i <= n; i++){
	    cin >> c;
	    if(c == 'H'){
	        ph[i] = ph[i - 1] + 1;
	        pp[i] = pp[i - 1];
	        ps[i] = ps[i - 1];
        }else if(c == 'P'){
            ph[i] = ph[i - 1];
	        pp[i] = pp[i - 1] + 1;
	        ps[i] = ps[i - 1];
        }else{
            ph[i] = ph[i - 1];
	        pp[i] = pp[i - 1];
	        ps[i] = ps[i - 1] + 1;
        }
    
	}
	int x;
	for(int i = 1; i <= n; i++){
	    for(int j = 0; j < 2; j++){
	        if(j == 0){
	            //c = 'P'
	            x = ph[i] + pp[n] - pp[i];
	            maxl = max(maxl, x);
	        }
	        if(j == 1){
	            x = ph[i] + ps[n] - ps[i];
	            maxl = max(maxl, x);
	        }
	    }
	}
	for(int i = 1; i <= n; i++){
	    for(int j = 0; j < 2; j++){
	        if(j == 0){
	            x = pp[i] + ph[n] - ph[i];
	            maxl = max(maxl, x);
	        }
	        if(j == 1){
	            x = pp[i] + ps[n] - ps[i];
	            maxl = max(maxl, x);
	        }
	    }
	}
	for(int i = 1; i <= n; i++){
	    for(int j = 0; j < 2; j++){
	        if(j == 0){
	            x = ps[i] + ph[n] - ph[i];
	            maxl = max(maxl, x);
	        }
	        if(j == 1){
	            x = ps[i] + pp[n] - pp[i];
	            maxl = max(maxl, x);
	        }
	    }
	}
	cout << maxl;
}