#include <iostream>
#include <cstdio>
using namespace std;
int n, maxl = 0;
int p[50001];
int first[7] = {0, -1, -1, -1, -1, -1, -1};
int main(){
    	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	cin >> n;
	int a, b, c;
	p[0] = 0;
	for(int i = 1; i <= n; i++){
	    cin >> a;
	    p[i] = (a + p[i - 1]) % 7;
	    //cout << p[i] << endl;
	    if(first[p[i]] == -1){
	        first[p[i]] = i;
	    }else{
	        maxl = max(i - first[p[i]], maxl);
	        
	    }
	    
	}
	cout << maxl;
}