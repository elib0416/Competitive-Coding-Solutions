#include <map>
#include <iostream>
using namespace std;
int n;
long long int p[200001];
long long int ans = 0;
int main()
{
    cin >> n;
    map<int, long long int> m;
    p[0] = 0;
    m[0] = 1;
    int k;
    for(int i = 1; i <= n; i++){
        cin >> k;
        p[i] = (p[i - 1] + k) % n;
        if(m.find(p[i]) != m.end()){
            ans += m[p[i]];
        }
        m[p[i]]++;
    }
    cout << ans;
    return 0;
}
