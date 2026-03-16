#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    long long q;
    cin >> q;
    vector<vector<long long>> cow(n, vector<long long>(n));
    vector<vector<long long>> photo(n - m + 1, vector<long long>(n - m + 1));
    long long othervalue = n - m + 1;
    long long maxatractiveness = 0;
    long long mminus1 = m - 1;
    while(q--){
        long long a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        long long amountincreased = c - cow[a][b];
        cow[a][b] += amountincreased;
        for(long long i = a - mminus1; i <= a; i++){
            for(long long j = b - mminus1; j <= b; j++){
                if(i < 0 || i >= othervalue || j < 0 || j >= othervalue){
                    continue;
                }
                photo[i][j] += amountincreased;
                maxatractiveness = max(maxatractiveness, photo[i][j]);
            }
        }
        cout << maxatractiveness << endl;
    }
}