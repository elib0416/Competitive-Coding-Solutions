#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    vector<string> base = cows;
    map<string, int> index = {
        {"Beatrice", 0}, {"Belinda", 1}, {"Bella", 2}, {"Bessie", 3}, {"Betsy", 4}, {"Blue", 5}, {"Buttercup", 6}, {"Sue", 7}
    };
    int n;
    cin >> n;
    vector<pair<int, int>> connections(n);
    string a, b, x1, x2, x3, x4;
    for(int i = 0; i < n; i++){
        cin >> a >> x1 >> x2 >> x3 >> x4 >> b;
        connections[i] = {index[a], index[b]};
    }
    do{
        bool good = true;
        for(auto [a, b] : connections){
            for(int i = 0; i < 8; i++){
                if(cows[i] == base[a]){
                    if(cows[max(i - 1, 0)] != base[b] && cows[min(i + 1, 7)] != base[b]){
                        good = false;
                        break;
                    }
                }
            }
        }
        if(good){
            for(auto s : cows){
                cout << s << endl;
            }
            return 0;
        }
    }while(next_permutation(cows.begin(), cows.end()));
}