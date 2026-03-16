#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    const long long int infi = 1e9 + 7;
    long long int n, a, b;
    cin >> n >> a >> b;
    vector<vector<char>> arr(n, vector<char>(n));
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    map<bool, long long int> errm;
    errm[true] = a;
    errm[false] = b;
    map<long long int, vector<pair<long long int, long long int>>> paths;
    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n; j++){
            long long int index = n * i + j;
            if(i != 0){
                paths[index].push_back({index - n, errm[arr[i][j] == arr[i - 1][j]]});
            }
            if(i != n - 1){
                paths[index].push_back({index + n, errm[arr[i][j] == arr[i + 1][j]]});
            }
            if(j != 0){
                paths[index].push_back({index - 1, errm[arr[i][j] == arr[i][j - 1]]});
            }
            if(j != n - 1){
                paths[index].push_back({index + 1, errm[arr[i][j] == arr[i][j + 1]]});
            }
        }
    }
    long long int maxi = 0;
    for(long long int i = 0; i < n * n; i++){
        vector<long long int> distances(n * n, infi);
        distances[i] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, i});
        while(!pq.empty()){
            auto current = pq.top();
            long long int index = current.second;
            long long int length = current.first;
            pq.pop();
            if(length < maxi){
                //continue;
            }
            for(auto x : paths[index]){
                if(distances[x.first] > length + x.second){
                    pq.push({length + x.second, x.first});
                    distances[x.first] = length + x.second;
                }
            }
        }
        for(long long int j = 0; j < n * n; j++){
            if(distances[j] == infi){
                continue;
            }
            maxi = max(maxi, distances[j]);
        }
    }
    cout << maxi;
}