#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int arr[maxn];
bool visited[maxn];
int numarr[maxn];
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n, a, count = 0;
    cin >> n;
    //cout << n << ' ';
    for(int i = 0; i < n; i++){
        cin >> a;
        //cout << a << ' ';
        a--;
        arr[i] = a;
        numarr[a]++;
    }
    //cout << endl;
    queue<int> Empty;
    for(int i = 0; i < n; i++){
        if(numarr[i] == 0){
            Empty.push(i);
        }
    }
    while(!Empty.empty()){
        int current = Empty.front();
        Empty.pop();
        numarr[arr[current]]--;
        if(numarr[arr[current]] == 0){
            Empty.push(arr[current]);
        }
    }
    for(int i = 0; i < n; i++){
        if(numarr[i] > 0){
            count++;
        }
    }
    cout << count;
}