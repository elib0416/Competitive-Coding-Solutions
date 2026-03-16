#include <bits/stdc++.h>
using namespace std;
struct plant{
  long long int h;
  long long int g;
  long long int t;
};
bool plantsort(plant& a, plant& b ){
    return (a.t < b.t);
}
long long int cdiv(long long int a, long long int b){
  return (a + b - 1) / b;
}
int main(){
  long long int t;
  cin >> t;
  while(t--){
    long long int n;
    cin >> n;
    vector<plant> plants(n);
    for (long long int i = 0; i < n; ++i){
      cin >> plants[i].h;
    }
    for (long long int i = 0; i < n; ++i){
      cin >> plants[i].g;
    }
    for (long long int i = 0; i < n; ++i){
      cin >> plants[i].t;
    }
    if(n == 1){
      if(plants[0].t == 0){
        cout << 0 << endl;
      }else {
        cout << -1 << endl;
      }
    }else if(n == 2){
      sort(plants.begin(), plants.end(), plantsort);
      if(plants[0].h > plants[1].h){
        cout << 0 << endl;
      }else{
        if (plants[0].g <= plants[1].g){
          cout << -1 << endl;
        }else{
          cout << cdiv((plants[1].h - plants[0].h + 1), (plants[0].g - plants[1].g)) << endl;
        }
      }
    }else{
      sort(plants.begin(), plants.end(), plantsort);
      long long int days = 0, max_days = 0;
      for(long long int i = 0; i < n-1; i++){
        if(plants[i].h <= plants[i + 1].h){
          if(plants[i].g <= plants[i + 1].g){
            max_days = -1;
            break;
          }else{
            days = cdiv((plants[i + 1].h - plants[i].h + 1), (plants[i].g - plants[i + 1].g));
            max_days = max(max_days, days);
          }
        }
      }
      for(long long int i = 0; i < n - 1; i++){
        if((plants[i].h + plants[i].g*max_days) <= (plants[i + 1].h + plants[i + 1].g*max_days)){
          max_days = -1;
          break;
        }
      }     
      cout << max_days << endl;
    }
  }
  return 0;
}