#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> arr(2001, vector<pair<int, int>>(2001, {-1, -1}));
    vector<pair<int, int>> posts(m);
    vector<int> distances(m);
    vector<int> distancepref(m + 1, 0);
    for(int i = 0; i < m; i++){
        cin >> posts[i].first >> posts[i].second;
        arr[posts[i].first][posts[i].second] = {i, 0};
    }
    int total_distance = 0;
    for(int i = 0; i < m; i++){
        int ni = (i + 1) % m;
        total_distance += abs(posts[i].first - posts[ni].first) + abs(posts[i].second - posts[ni].second);
        distances[i] = abs(posts[i].first - posts[ni].first) + abs(posts[i].second - posts[ni].second);
        distancepref[i + 1] = distancepref[i] + distances[i];
        //cout << posts[i].first << ' ' << posts[i].second << ' ' << posts[ni].first << ' ' << posts[ni].second << endl;
        if(posts[i].first == posts[ni].first && posts[ni].second >= posts[i].second){
            for(int j = posts[i].second + 1; j < posts[ni].second; j++){
                arr[posts[i].first][j] = {i, abs(j - posts[i].second)};
            }
        }else if(posts[i].first == posts[ni].first && posts[ni].second < posts[i].second){
            for(int j = posts[ni].second + 1; j < posts[i].second; j++){
                arr[posts[i].first][j] = {i, abs(posts[i].second - j)};
            }
        }else if(posts[i].second == posts[ni].second && posts[ni].first >= posts[i].first){
            for(int j = posts[i].first + 1; j < posts[ni].first; j++){
                arr[j][posts[i].second] = {i, abs(j - posts[i].first)};
            }
        }else{
            for(int j = posts[ni].first + 1; j < posts[i].first; j++){
                arr[j][posts[i].second] = {i, abs(posts[i].first - j)};
            }
        }
    }
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ';
        int post1 = arr[a][b].first;
        int post2 = arr[c][d].first;
        //cout << post1 << ' ' << post2 << endl; 
        int ans = min(abs(distancepref[post2] + arr[c][d].second - distancepref[post1] - arr[a][b].second), distancepref[m] - abs(distancepref[post2] + arr[c][d].second - distancepref[post1] - arr[a][b].second));
        cout << ans << endl;
    }
}