#include <iostream>
#include <map>
using namespace std;
map<long long int, long long int> m;
int n;
long long int k, countf = 0;
int main(){
    long long int p = 0;
    cin >> n >> k;
    long long int num;
    m[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> num;
        p += num;
        if(m.count(p - k)){
            countf += m[p - k];
        }
        m[p]++;
    }
    cout << countf;
}