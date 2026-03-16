#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

const int MAX_N = 100001;
int n,  b,  k;
int diff[MAX_N] = {0};
int p[MAX_N] = {0};
int shortest = INT_MAX;

int main()
{
    freopen("maxcross.in",  "r",  stdin);
    freopen("maxcross.out",  "w",  stdout);
    cin >> n >> b >> k;
    int x;
    for(int i = 0; i < b; i++){
        cin >> x;
        diff[x - 1]++;
        diff[x]--;
    }
    p[0] = diff[0];
    for(int i = 1; i < n; i++){
        p[i] = p[i - 1] + diff[i];
    }
    for(int i = 0; i <= n - k; i++){
        x = p[i + k - 1] - (i > 0 ? p[i - 1] : 0);
        shortest = min(shortest,  x);
    }
    cout << shortest << endl;
    return 0;
}
