#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        string answer(n, '.');
        int lastG = -100002;
        int lastH = -100002;
        int number = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'G'){
                if(i - lastG > m){
                    number++;
                    if(i + m >= n){
                        lastG = i;
                    }else{
                        lastG = i + m;
                    }
                    if(answer[lastG] == 'H'){
                        lastG--;
                    }
                    answer[lastG] = 'G';
                }
            }else{
                if(i - lastH > m){
                    number++;
                    if(i + m >= n){
                        lastH = i;
                    }else{
                        lastH = i + m;
                    }
                    if(answer[lastH] == 'G'){
                        lastH--;
                    }
                    answer[lastH] = 'H';
                }
            }
        }
        cout << number << endl << answer << endl;
    }
}