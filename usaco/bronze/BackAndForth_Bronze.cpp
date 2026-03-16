#include <bits/stdc++.h>
using namespace std;
set<int> possibles;
void dfs(vector<int> tank1, vector<int> tank2, int tank, int day, int amount){
    if(day == 0){
        possibles.insert(amount);
        return;
    }
    //cout << day << ' ' << tank << ' ' << amount << endl;
    if (tank == 1) {
        for (int i = 0; i < (int)tank1.size(); i++) {
            int value = tank1[i];
            vector<int> newTank1 = tank1;
            vector<int> newTank2 = tank2;
            newTank1.erase(newTank1.begin() + i);
            newTank2.push_back(value);
            dfs(newTank1, newTank2, 2, day - 1, amount - value);
        }
    } else {
        for (int i = 0; i < (int)tank2.size(); i++) {
            int value = tank2[i];
            vector<int> newTank1 = tank1;
            vector<int> newTank2 = tank2;
            newTank2.erase(newTank2.begin() + i);
            newTank1.push_back(value);
            dfs(newTank1, newTank2, 1, day - 1, amount + value);
        }
    }
}
int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> tank1(10), tank2(10);
    for(int i = 0; i < 10; i++){
        cin >> tank1[i];
        //cout << tank1[i] << ' ';
    }
    //cout << endl;
    for(int i = 0; i < 10; i++){
        cin >> tank2[i];
        //cout << tank2[i] << ' ';
    }
    //cout << endl;
    dfs(tank1, tank2, 1, 4, 1000);
    cout << possibles.size();
}