#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> locations0, locations1;
    long long total = 0;
    locations0.push_back(0);
    locations1.push_back(0);
    for(long long i = 0; i < n; i++){
        char c;
        cin >> c;
        arr[i] = (c == 'G');
        if(arr[i]){
            locations1.push_back(i + 1);
        }else{
            locations0.push_back(i + 1);
        }
    }
    locations0.push_back(n + 1);
    locations1.push_back(n + 1);
    for(long long i = 1; i < locations0.size() - 1; i++){
        long long numleft = locations0[i] - locations0[i - 1] - 1;
        long long numright = locations0[i + 1] - locations0[i] - 1;
        if(numleft == 0 && numright >= 2){
            total += numright - 1;
        }else if(numright == 0 && numleft >= 2){
            total += numleft - 1;
        }else if(numleft >= 1 && numright >= 1){
            total += (numleft + 1) * (numright + 1) - 3;
        }
        //cout << total << endl;
        //cout << i << endl;
    }
    for(long long i = 1; i < locations1.size() - 1; i++){
        long long numleft = locations1[i] - locations1[i - 1] - 1;
        long long numright = locations1[i + 1] - locations1[i] - 1;
        if(numleft == 0 && numright >= 2){
            total += numright - 1;
        }else if(numright == 0 && numleft >= 2){
            total += numleft - 1;
        }else if(numleft >= 1 && numright >= 1){
            total += (numleft + 1) * (numright + 1) - 3;
        }
        //cout << total << endl;
    }
    /*for(long long x : locations0){
        cout << x << ' ';
    }
    cout << endl;
    for(long long x : locations1){
        cout << x << ' ';
    }
    cout << endl;*/
    cout << total;
}