#include <iostream>
#include <cstdio>
using namespace std;
int n, q;
int arr[100001], h[100001], g[100001], j[100001];
//h-1 g-2 j-3
int main(){
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	cin >> n >> q;
	int a, b, ch, cg, cj;
	h[0] = 0;
	g[0] = 0;
	j[0] = 0;
	int curh = 0, curg = 0, curj = 0;
	for(int i = 1; i <= n; i++){
	    cin >> arr[i];
	    if(arr[i] == 1){
	        curh++;
	    }else if(arr[i] == 2){
	        curg++;
	    }else{
	        curj++;
	    }
	    h[i] = curh;
	    g[i] = curg;
	    j[i] = curj;
	}
	for(int i = 0; i < q; i++){
	    cin >> a >> b;
	    ch = h[b] - h[a - 1];
	    cg = g[b] - g[a - 1];
	    cj = j[b] - j[a - 1];
	    cout << ch << ' ' << cg << ' ' << cj << endl;
	}
	
}