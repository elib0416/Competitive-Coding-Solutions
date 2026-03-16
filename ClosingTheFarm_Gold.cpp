#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, m, A, B, num = 0;
const int maxn = 2e5 + 1;
vector<int> height(maxn), father(maxn);
vector<bool> unblocked(maxn, false);
int find(int x){
    if(father[x] == x){
        return x;
    }
    return find(father[x]);
}
void combine(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    //cout << roota << ' ' << rootb << endl;
    if(roota == rootb){
        return;
    }else{
        num--;
    }
    if(height[roota] > height[rootb]){
        father[rootb] = roota;
        height[roota] = max(height[roota], height[rootb] + 1);
    }else{
        father[roota] = rootb;
        height[rootb] = max(height[rootb], height[roota] + 1);
    }
}
int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    map<int, vector<int>> paths;
    cin >> n >> m;
    vector<int> farms(n), result(n);
    for(int i = 0; i < m; i++){
        cin >> A >> B;
        A--;
        B--;
        paths[A].push_back(B);
        paths[B].push_back(A);
    }
    for(int i = 0; i < n; i++){
        cin >> farms[n - 1 - i];
        farms[n - 1 - i]--;
    }
    for(int i = 0; i < n; i++){
        father[i] = i;
        height[i] = 0;
    }
    /*(for(int i = 0; i < n; i++){
        cout << farms[i] << ' ';
    }
    cout << endl;*/
    for(int i = 0; i < n; i++){
        int number = farms[i];
        num++;
        unblocked[number] = true;
        for(int x : paths[number]){
            if(unblocked[x]){
                //cout << i << ' ' << x << endl;
                combine(number, x);
            }
        }
        //cout << num << endl;
        if(num == 1){
            result[n - 1 - i] = 1;
        }else{
            result[n - 1 - i] = 0;
        }
        /*(for(int j = 0; j < n; j++){
            cout << father[j] << ' ';
        }
        cout << endl;*/
    }
    for(int i = 0; i < n; i++){
        if(result[i] == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

