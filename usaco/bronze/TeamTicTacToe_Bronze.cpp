#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<vector<char>> arr(3, vector<char>(3));
    int indivi = 0;
    int team = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    set<char> indiwinners;
    set<pair<char, char>> winners;
    for(int i = 0; i < 3; i++){
        set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(arr[i][j]);
        }
        /*for(auto c : s){
            cout << c << ' ';
        }
        cout << endl;*/
        if(s.size() == 2){
            vector<char> stuff(2);
            int in = 0;
            for(char c : s){
                stuff[in] = c;
                in++;
            }
            //cout << "r " << i << ' ' << j << ' ' << stuff[0] << stuff[1];
            winners.insert({stuff[0], stuff[1]});
            winners.insert({stuff[1], stuff[0]});
        }else if(s.size() == 1){
            for(char c : s){
                indiwinners.insert(c);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(arr[j][i]);
        }
        /*for(auto c : s){
            cout << c << ' ';
        }
        cout << endl;*/
        if(s.size() == 2){
            vector<char> stuff(2);
            int in = 0;
            for(char c : s){
                stuff[in] = c;
                in++;
            }
            winners.insert({stuff[0], stuff[1]});
            winners.insert({stuff[1], stuff[0]});
        }else if(s.size() == 1){
            for(char c : s){
                indiwinners.insert(c);
            }
        }
    }
    set<char> s;
    for(int i = 0; i < 3; i++){
        s.insert(arr[i][i]);
    }
    if(s.size() == 2){
        vector<char> stuff(2);
        int in = 0;
        for(char c : s){
            stuff[in] = c;
            in++;
        }
        winners.insert({stuff[0], stuff[1]});
        winners.insert({stuff[1], stuff[0]});
    }else if(s.size() == 1){
        for(char c : s){
            indiwinners.insert(c);
        }
    }
    s.clear();
    for(int i = 0; i < 3; i++){
        s.insert(arr[i][2 - i]);
    }
    if(s.size() == 2){
        vector<char> stuff(2);
        int in = 0;
        for(char c : s){
            stuff[in] = c;
            in++;
        }
        winners.insert({stuff[0], stuff[1]});
        winners.insert({stuff[1], stuff[0]});
    }else if(s.size() == 1){
        for(char c : s){
            indiwinners.insert(c);
        }
    }
    cout << indiwinners.size() << endl;
    cout << winners.size() / 2;
}