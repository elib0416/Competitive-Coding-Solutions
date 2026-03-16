#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

const int MAX_N = 100001;
int n, b, k;
int diff[MAX_N] = {0};
int p[MAX_N] = {0};
int shortest = INT_MAX;

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> n >> k >> b;
    int x;
    for(int i = 0; i < b; i++){
        cin >> x;
        diff[x]++;
    }
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + diff[i];
    }
    for(int i = 0; i <= n - k; i++){
        x = p[i+k] - p[i];
        shortest = min(shortest, x);
    }
    cout << shortest << endl;
    return 0;
}
